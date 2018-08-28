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
//Class header
#include "WAVE_Muxer.hpp"
//Local
#include <Std++/Multimedia/AudioStream.hpp>
#include <Std++/Streams/Writers/DataWriter.hpp>
#include "WAVE.h"

//Constructor
WAVE_Muxer::WAVE_Muxer(const Format &refFormat, ASeekableOutputStream &refOutput) : Muxer(refFormat, refOutput)
{
}

//Public methods
void WAVE_Muxer::Finalize()
{
	uint32 currentOffset = (uint32)this->outputStream.GetCurrentOffset();
	DataWriter writer(false, this->outputStream);
	this->outputStream.SetCurrentOffset(this->riffTagSizeOffset);
	writer.WriteUInt32(currentOffset - 8); //sizeof("RIFF") + sizeof(chunkSize)

	this->outputStream.SetCurrentOffset(this->dataChunkSizeOffset);
	writer.WriteUInt32(currentOffset - this->dataChunkSizeOffset - 4);
}

void WAVE_Muxer::WriteHeader()
{
	AudioStream *stream = (AudioStream *)this->GetStream(0);

	uint16 bitsPerSample = this->GetBitsPerSample(stream->GetCodingFormat()->GetId());
	uint16 blockAlign = stream->nChannels * bitsPerSample / 8;

	DataWriter writer(false, this->outputStream);
	//riff chunk
	writer.WriteUInt32(WAVE_RIFFCHUNK_CHUNKID);
	this->riffTagSizeOffset = (uint32)this->outputStream.GetCurrentOffset();
	writer.WriteUInt32(0); //file size
	writer.WriteUInt32(WAVE_RIFFCHUNK_RIFFTYPE);

	//format chunk
	writer.WriteUInt32(WAVE_FORMATCHUNK_CHUNKID);
	writer.WriteUInt32(16); //size of format chunk
	writer.WriteUInt16((uint16)(stream->GetCodingFormat()->GetId()));
	writer.WriteUInt16(stream->nChannels);
	writer.WriteUInt32(stream->sampleRate);
	writer.WriteUInt32(stream->sampleRate * blockAlign);
	writer.WriteUInt16(blockAlign);
	writer.WriteUInt16(bitsPerSample);

	//data chunk
	writer.WriteUInt32(WAVE_DATACHUNK_CHUNKID);
	this->dataChunkSizeOffset = (uint32)this->outputStream.GetCurrentOffset();
	writer.WriteUInt32(0); //chunk size
}

void WAVE_Muxer::WritePacket(const Packet &packet)
{
	this->outputStream.WriteBytes(packet.GetData(), packet.GetSize());
}

//Private methods
uint16 WAVE_Muxer::GetBitsPerSample(CodingFormatId codingFormatId) const
{
	switch(codingFormatId)
	{
		//case CodingFormatId::PCM_Float32LE:
			//return 32;
		case CodingFormatId::PCM_S16LE:
			return 16;
	}

	NOT_IMPLEMENTED_ERROR;
	return 0;
}