/*
 * Copyright (c) 2017-2018 Amir Czwink (amir130@hotmail.de)
 *
 * This file is part of Std++.
 *
 * Std++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Std++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Std++.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
//Local
#include "../Containers/LinkedList/LinkedList.hpp"
#include "../Multitasking/ConditionVariable.hpp"
#include "../Multitasking/Mutex.hpp"
#include "../Multitasking/Thread.hpp"
#include "../Streams/SeekableInputStream.hpp"
#include "../Time/Clock.hpp"
#include "../Time/Timer.hpp"
#include "AudioStream.hpp"
#include "Demuxer.hpp"
#include "Format.hpp"
#include "SubtitleStream.hpp"
#include "VideoStream.hpp"

namespace StdPlusPlus
{
	namespace Multimedia
	{
		//Forward declarations
		class MediaPlayer;
	}
}

namespace _stdpp
{
	class DecoderThread : public StdPlusPlus::Thread
	{
	public:
		//Constructor
		DecoderThread(StdPlusPlus::Multimedia::MediaPlayer *player, StdPlusPlus::Multimedia::CodecId encodingCodec);

		//Destructor
		~DecoderThread();

		//Methods
		void FlushInputQueue();
		void FlushOutputQueue();
		StdPlusPlus::Multimedia::Packet *TryGetNextOutputPacket();

		//Inline
		inline void AddInputPacket(StdPlusPlus::Multimedia::Packet *packet)
		{
			this->inputPacketQueueLock.Lock();
			this->inputPacketQueue.InsertTail(packet);
			this->inputPacketQueueLock.Unlock();
			this->inputPacketQueueSignal.Signal();
		}

		inline void Run()
		{
			this->work = true;
			this->workLock.Lock();
			this->workSignal.Signal();
			this->workLock.Unlock();
		}

		inline void SetStreamIndex(uint32 streamIndex)
		{
			this->streamIndex = streamIndex;
		}

		inline void Shutdown()
		{
			this->shutdown = true;
			this->work = false;

			this->workLock.Lock();
			this->workSignal.Signal();
			this->workLock.Unlock();

			this->inputPacketQueueSignal.Signal();
			this->Join();
		}

		inline void Stop()
		{
			this->work = false;
			this->inputPacketQueueSignal.Signal();
		}

	private:
		//Members
		StdPlusPlus::Multimedia::MediaPlayer *player;
		bool shutdown;
		bool work;
		StdPlusPlus::Mutex workLock;
		StdPlusPlus::ConditionVariable workSignal;
		volatile bool working;
		uint32 streamIndex;
		StdPlusPlus::Multimedia::Decoder *decoder;
		StdPlusPlus::Multimedia::Encoder *encoder;
		StdPlusPlus::LinkedList<StdPlusPlus::Multimedia::Packet *> inputPacketQueue;
		StdPlusPlus::Mutex inputPacketQueueLock;
		StdPlusPlus::ConditionVariable inputPacketQueueSignal;
		StdPlusPlus::LinkedList<StdPlusPlus::Multimedia::Packet *> outputPacketQueue;
		StdPlusPlus::Mutex outputPacketQueueLock;

		//Methods
		StdPlusPlus::Multimedia::Packet *GetNextInputPacket();
		int32 ThreadMain();
		bool WaitForWork();

		//Inline
		inline void AddOutputPacket(StdPlusPlus::Multimedia::Packet *packet)
		{
			this->outputPacketQueueLock.Lock();
			this->outputPacketQueue.InsertTail(packet);
			this->outputPacketQueueLock.Unlock();
		}
	};

	class DemuxerThread : public StdPlusPlus::Thread
	{
	public:
		//Constructor
		DemuxerThread(StdPlusPlus::Multimedia::MediaPlayer *player);

		//Inline
		inline void Connect(DecoderThread *audioDecodeThread, DecoderThread *videoDecodeThread)
		{
			this->audioDecodeThread = audioDecodeThread;
			this->videoDecodeThread = videoDecodeThread;
		}

		inline void Run()
		{
			this->work = true;
			this->workLock.Lock();
			this->workSignal.Signal();
			this->workLock.Unlock();
		}

		inline void SetStreamIndices(uint32 videoStreamIndex, uint32 audioStreamIndex)
		{
			this->videoStreamIndex = videoStreamIndex;
			this->audioStreamIndex = audioStreamIndex;
		}

		inline void Shutdown()
		{
			this->shutdown = true;
			this->work = false;

			this->workLock.Lock();
			this->workSignal.Signal();
			this->workLock.Unlock();
			this->Join();
		}

	private:
		//Members
		StdPlusPlus::Multimedia::MediaPlayer *player;
		StdPlusPlus::Multimedia::Demuxer *demuxer;
		bool shutdown;
		bool work;
		StdPlusPlus::Mutex workLock;
		StdPlusPlus::ConditionVariable workSignal;
		volatile bool working;
		uint32 audioStreamIndex;
		DecoderThread *audioDecodeThread;
		uint32 videoStreamIndex;
		DecoderThread *videoDecodeThread;

		//Methods
		int32 ThreadMain();
	};
}

namespace StdPlusPlus
{
	namespace UI
	{
		//Forward declarations
		class VideoWidget;
	}

	namespace Multimedia
	{
		class MediaPlayer
		{
		public:
			//Constructor
			MediaPlayer(SeekableInputStream &inputStream);

			//Destructor
			~MediaPlayer();

			//Methods
			void Pause();
			void Play();

			//Inline
			inline Demuxer *GetDemuxer()
			{
				return this->demuxer;
			}

			inline bool IsPlaying() const
			{
				return this->isPlaying;
			}

			inline void SetVideoOutput(UI::VideoWidget *videoWidget)
			{
				this->videoWidget = videoWidget;
			}

		private:
			//Members
			SeekableInputStream &inputStream;
			const Format *format;
			Demuxer *demuxer;
			Map<uint32, AudioStream *> audioStreams;
			uint32 audioStreamIndex;
			Map<uint32, SubtitleStream *> subtitleStreams;
			Map<uint32, VideoStream *> videoStreams;
			uint32 videoStreamIndex;
			bool isPlaying;
			StdPlusPlus::Clock clock;
			/**
			 * In microseconds.
			 */
			uint64 masterClock;
			Timer masterClockTimer;
			Packet *nextVideoPacket;
			/**
			 * In microseconds.
			 * Time until nextVideoPacket should be presented.
			 */
			int64 videoFrameDelay;
			UI::VideoWidget *videoWidget;

			_stdpp::DemuxerThread demuxerThread;
			_stdpp::DecoderThread audioDecodeThread;
			_stdpp::DecoderThread videoDecodeThread;

			//Eventhandlers
			void OnMasterClockTriggered();

			//Methods
			void HaltPlayback();
		};
	}
}