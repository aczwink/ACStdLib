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
/*//Class header
#include <Std++/FileSystem/ContainerFile.hpp>
//Local
#include <Std++/Compression/Decompressor.hpp>
#include <Std++/FileSystem/WritableContainerDirectory.hpp>
#include <Std++/FileSystem/EmbeddedFileInputStream.hpp>
#include <Std++/Streams/ChainedInputStream.hpp>
#include <Std++/Streams/BufferedInputStream.hpp>
#include <Std++/FileSystem/ArchiveFileSystem.hpp>
//Namespaces
using namespace StdXX;
using namespace StdXX::FileSystem;

//Public methods
void ContainerFile::ChangePermissions(const Permissions &newPermissions)
{
	this->permissions = newPermissions.Clone();
}

UniquePointer<OutputStream> ContainerFile::OpenForWriting()
{
	//can not open read only file for writing
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return nullptr;
}

NodeInfo ContainerFile::QueryInfo() const
{
	NodeInfo nodeInfo;

	nodeInfo.permissions = this->permissions.IsNull() ? nullptr : this->permissions->Clone();
	nodeInfo.size = this->header.uncompressedSize;
	nodeInfo.storedSize = this->header.compressedSize;

	return nodeInfo;
}*/