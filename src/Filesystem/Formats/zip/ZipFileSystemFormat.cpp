/*
* Copyright (c) 2019 Amir Czwink (amir130@hotmail.de)
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
#include "ZipFileSystemFormat.hpp"
//Namespaces
using namespace _stdxx_;
using namespace StdXX;

//Public methods
uint64 ZipFileSystemFormat::FindEndOfCentralDirectoryOffset(SeekableInputStream &inputStream) const
{
	const uint32 endOfCentralDirectoryStaticSize = 22;
	const uint32 endOfCentralDirectoryMaxSize = endOfCentralDirectoryStaticSize + Unsigned<uint16>::Max();

	uint32 bufferSize = (uint32)Math::Min((uint64)endOfCentralDirectoryMaxSize, inputStream.GetSize());
	FixedSizeBuffer buffer(bufferSize);

	inputStream.SetCurrentOffset(inputStream.GetSize() - bufferSize);
	uint32 nBytesRead = inputStream.ReadBytes(buffer.data(), bufferSize);
	ASSERT(nBytesRead == bufferSize, u8"REPORT THIS PLEASE!");
	ASSERT(inputStream.IsAtEnd(), u8"REPORT THIS PLEASE!");

	uint32 offset = bufferSize - endOfCentralDirectoryStaticSize + sizeof(zipEndOfCentralDirectorySignature);
	while (true)
	{
		offset = buffer.FindReversedUInt32(zipEndOfCentralDirectorySignature, false, offset);
		if(offset == Unsigned<uint32>::Max())
			break;
		if(this->ValidateEndOfCentralDirectory(buffer, offset))
			return inputStream.GetSize() - buffer.size() + offset;
	}

	return Unsigned<uint64>::Max();
}

bool ZipFileSystemFormat::ValidateEndOfCentralDirectory(const FixedSizeBuffer &buffer, uint32 offset) const
{
	BufferInputStream bufferInputStream(buffer.data() + offset, buffer.size() - offset);
	bufferInputStream.Skip(20);
	DataReader dataReader(false, bufferInputStream);

	uint16 commentLength = dataReader.ReadUInt16();
	return bufferInputStream.GetRemainingBytes() == commentLength;
}
