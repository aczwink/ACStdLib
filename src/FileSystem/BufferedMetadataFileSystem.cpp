/*
 * Copyright (c) 2019-2020 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/FileSystem/BufferedMetadataFileSystem.hpp>
//Namespaces
using namespace StdXX;
using namespace StdXX::FileSystem;

//Local functions
template<typename T>
static AutoPointer<T> GetNodeImpl(const Path& path, AutoPointer<T> root)
{
	if(path.IsRoot())
		return root;

	Path leftPath = path;
	if(leftPath.IsAbsolute()) //skip root slash
		leftPath = leftPath.String().SubString(1);
	AutoPointer<T> node = root;
	while(true)
	{
		Path remaining;
		String name = leftPath.SplitOutmostPathPart(remaining);
		leftPath = remaining;

		ASSERT(node->GetType() == NodeType::Directory, u8"Only directories can have children");
		using dirType = typename Type::Conditional<Type::IsConst<T>::value, const Directory, Directory>::type;
		node = node.template Cast<dirType>()->GetChild(name);

		if(leftPath.String().IsEmpty())
			break;
	}

	return node;
}

//Public methods
UniquePointer<OutputStream> BufferedMetadataFileSystem::CreateFile(const Path &filePath)
{
	return this->GetDirectory(filePath.GetParent())->CreateFile(filePath.GetName());
}

AutoPointer<Node> BufferedMetadataFileSystem::GetNode(const Path &path)
{
	return GetNodeImpl<Node>(path, this->GetRoot());
}

AutoPointer<const Node> BufferedMetadataFileSystem::GetNode(const Path &path) const
{
	return GetNodeImpl<const Node>(path, this->GetRoot());
}