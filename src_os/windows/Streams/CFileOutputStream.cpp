/*
* Copyright (c) 2017 Amir Czwink (amir130@hotmail.de)
*
* This file is part of ACStdLib.
*
* ACStdLib is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ACStdLib is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ACStdLib.  If not, see <http://www.gnu.org/licenses/>.
*/
//Class Header
#include <ACStdLib/Streams/FileOutputStream.hpp>
//Global
#include <Windows.h>
//Local
#include <ACStdLib/Containers/Strings/UTF-16/UTF16String.hpp>
//Namespaces
using namespace ACStdLib;

//Constructor
FileOutputStream::FileOutputStream(const Path &refPath)
{
	UTF16String fileNameUTF16(refPath.GetString().GetUTF16());

	this->pFileHandle = CreateFileW((LPCWSTR)fileNameUTF16.GetC_Str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
}

//Destructor
FileOutputStream::~FileOutputStream()
{
	CloseHandle(this->pFileHandle);
}

//Public methods
uint64 FileOutputStream::GetCurrentOffset() const
{
	LARGE_INTEGER offset, result;

	offset.QuadPart = 0;

	SetFilePointerEx(this->pFileHandle, offset, &result, FILE_CURRENT);

	return result.QuadPart;
}

void FileOutputStream::SetCurrentOffset(uint64 offset)
{
	LARGE_INTEGER liOffset;

	liOffset.QuadPart = offset;

	SetFilePointerEx(this->pFileHandle, liOffset, nullptr, FILE_BEGIN);
}

void FileOutputStream::WriteByte(byte b)
{
	DWORD nBytesWritten;

	WriteFile(this->pFileHandle, &b, 1, &nBytesWritten, NULL);
}

uint32 FileOutputStream::WriteBytes(const void *pSource, uint32 size)
{
	DWORD nBytesWritten;

	WriteFile(this->pFileHandle, pSource, size, &nBytesWritten, NULL);

	return nBytesWritten;
}