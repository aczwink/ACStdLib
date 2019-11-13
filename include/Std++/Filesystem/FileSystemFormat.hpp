/*
 * Copyright (c) 2018-2019 Amir Czwink (amir130@hotmail.de)
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
#include "../Streams/SeekableInputStream.hpp"
#include "FileSystem.hpp"

namespace StdXX
{
	class FileSystemFormat
	{
	public:
		//Abstract
		virtual FileSystem* CreateFileSystem(const Path &fileSystemPath) const = 0;
		virtual String GetId() const = 0;
		virtual String GetName() const = 0;
		virtual float32 Matches(SeekableInputStream &inputStream) const = 0;
		virtual FileSystem *OpenFileSystem(const Path &fileSystemPath, bool writable) const = 0;

		//Functions
		static STDPLUSPLUS_API void Register(const FileSystemFormat *fileSystemFormat);
	};
}