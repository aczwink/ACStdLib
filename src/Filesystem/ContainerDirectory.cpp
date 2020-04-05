/*
 * Copyright (c) 2018-2020 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/Filesystem/ContainerDirectory.hpp>
//Local
#include <Std++/Filesystem/DirectoryIterator.hpp>
#include <Std++/Filesystem/ContainerFileSystem.hpp>
#include <Std++/Filesystem/MemoryFile.hpp>
//Namespaces
using namespace StdXX;

//Public methods
void ContainerDirectory::ChangePermissions(const Filesystem::NodePermissions &newPermissions)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

UniquePointer<OutputStream> ContainerDirectory::CreateFile(const String &name)
{
	MemoryFile* file = new MemoryFile;
	this->AddChild(name, file);

	this->fileSystem->isFlushed = false;

	return file->OpenForWriting();
}

void ContainerDirectory::CreateSubDirectory(const String &name)
{
	this->AddChild(name, new ContainerDirectory(name, this));

	this->fileSystem->isFlushed = false;
}

FileSystem *ContainerDirectory::GetFileSystem()
{
	return this->fileSystem;
}

const FileSystem *ContainerDirectory::GetFileSystem() const
{
	return this->fileSystem;
}

AutoPointer<const Directory> ContainerDirectory::GetParent() const
{
	return this->parent;
}

Path ContainerDirectory::GetPath() const
{
	if(this->parent)
		return this->parent->GetPath() / this->name;

	return Path(u8"/");
}

FileSystemNodeInfo ContainerDirectory::QueryInfo() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return FileSystemNodeInfo();
}