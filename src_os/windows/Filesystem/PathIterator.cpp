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
#include <Std++/Filesystem/DirectoryIterator.hpp>
//Local
#include <Std++/ErrorHandling/FileNotFoundException.hpp>
//Namespaces
using namespace StdPlusPlus;

//Constructor
PathIterator::PathIterator(const Path &path, bool end)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

//Destructor
PathIterator::~PathIterator()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

//Operators
PathIterator &PathIterator::operator++()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return *this;
}

bool PathIterator::operator!=(const PathIterator &other) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return 0;
}