/*
 * Copyright (c) 2018-2021 Amir Czwink (amir130@hotmail.de)
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
//Local
#include <Std++/Multitasking/Mutex.hpp>
#include "Std++/Streams/SeekableInputStream.hpp"

namespace StdXX
{
	class EmbeddedFileInputStream : public SeekableInputStream
	{
	public:
		//Constructor
		EmbeddedFileInputStream(uint64 offset, uint64 size, SeekableInputStream& baseInputStream, Mutex& baseInputStreamLock);

		//Methods
		uint32 GetBytesAvailable() const override;
		uint64 QueryCurrentOffset() const override;
		uint64 QueryRemainingBytes() const override;
		uint64 QuerySize() const override;
		bool IsAtEnd() const override;
		uint32 ReadBytes(void *destination, uint32 count) override;
		uint32 Skip(uint32 nBytes) override;
		void SeekTo(uint64 offset) override;

	private:
		//Members
		uint64 offset;
		uint64 size;
		SeekableInputStream& baseInputStream;
		Mutex& baseInputStreamLock;
		uint64 currentOffset;
	};
}