/*
* Copyright (c) 2019-2021 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/FileSystem/Format.hpp>
#include <Std++/Filetypes/UTIConstants.hpp>
#include <Std++/Buffers/FixedSizeBuffer.hpp>
#include <Std++/Streams/BufferInputStream.hpp>
#include <Std++/Streams/Readers/DataReader.hpp>
#include <Std++/Streams/FileInputStream.hpp>
#include "Zip.hpp"
#include "ZipFileSystem.hpp"

namespace _stdxx_
{
	class ZipFileSystemFormat : public StdXX::FileSystem::Format
	{
	public:
		//Methods
		StdXX::FileSystem::RWFileSystem* CreateFileSystem(const StdXX::FileSystem::Path &fileSystemPath) const override;

		StdXX::String GetId() const override
		{
			return StdXX::FileTypes::UTI::zip;
		}

		StdXX::String GetName() const override
		{
			return u8"ZIP archive";
		}

		float32 Matches(StdXX::SeekableInputStream &inputStream) const override
		{
			if(this->FindEndOfCentralDirectoryOffset(inputStream) != StdXX::Unsigned<uint64>::Max())
				return 1;
			return 0;
		}

		StdXX::FileSystem::RWFileSystem *OpenFileSystem(const StdXX::FileSystem::Path &fileSystemPath,
												  const StdXX::FileSystem::OpenOptions& options) const override;
		StdXX::FileSystem::ReadableFileSystem *OpenFileSystemReadOnly(const StdXX::FileSystem::Path &fileSystemPath,
																const StdXX::FileSystem::OpenOptions& options) const override;

	private:
		//Methods
		uint64 FindEndOfCentralDirectoryOffset(StdXX::SeekableInputStream& inputStream) const;
		StdXX::FileSystem::RWFileSystem *OpenFileSystem(const StdXX::FileSystem::Path &fileSystemPath,
														const StdXX::FileSystem::OpenOptions& options, bool writable) const;
		bool ValidateEndOfCentralDirectory(const StdXX::FixedSizeBuffer& buffer, uint32 offset) const;
	};
}