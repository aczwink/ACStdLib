/*
* Copyright (c) 2017-2020 Amir Czwink (amir130@hotmail.de)
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
//Class Header
#include <Std++/Containers/Strings/UTF32String.hpp>
//Local
#include <Std++/Containers/Strings/StringUtil.h>
#include <Std++/Char.hpp>
//Namespaces
using namespace StdXX;

//Operators
UTF32String &UTF32String::operator=(const UTF32String &refString)
{
	this->EnsureCapacity(refString.nElements);

	this->nElements = refString.nElements;

	MemCopy(this->data, refString.data, this->GetSize());
	this->data[this->nElements] = 0;

	return *this;
}

UTF32String &UTF32String::operator=(uint8 c)
{
	this->EnsureCapacity(1);

	this->data[0] = c;
	this->data[1] = 0;

	this->nElements = 1;

	return *this;
}

UTF32String &UTF32String::operator=(const uint8 *pString)
{
	uint32 length;

	length = GetStringLength((const char *)pString);
	this->EnsureCapacity(length);

	for(uint32 i = 0; i < length; i++)
		this->data[i] = pString[i];

	this->nElements = length;
	this->data[this->nElements] = 0;

	return *this;
}

UTF32String &UTF32String::operator=(const uint16 *pString)
{
	uint32 length;

	this->nElements = 0;
	length = GetStringLength(pString);

	this->EnsureCapacity(length);

	for(uint32 i = 0; i < length; i++)
	{
		this->data[this->nElements] = pString[i];

		this->nElements++;
	}
	this->data[this->nElements] = 0;

	return *this;
}

UTF32String &UTF32String::operator+=(const UTF32String &refString)
{
	this->EnsureAdditionalCapacity(refString.GetLength());

	MemCopy(&this->data[this->nElements], refString.data, refString.GetSize());
	this->nElements += refString.GetLength();
	this->data[this->nElements] = 0;

	return *this;
}

//Public methods
UTF32String UTF32String::SubString(uint32 beginOffset, uint32 length) const
{
	UTF32String buffer;

	if(length > 0)
	{
		buffer.EnsureCapacity(length);

		MemCopy(buffer.data, this->data + beginOffset, length * sizeof(*buffer.data));
		buffer.nElements = length;
		buffer[length] = 0;
	}

	return buffer;
}

UTF32String UTF32String::ToLowercase() const
{
	UTF32String buffer;

	buffer.EnsureCapacity(this->GetLength());
	for(uint32 i = 0; i < this->GetLength(); i++)
	{
		buffer.data[i] = StdXX::ToLowercase(this->data[i]);
	}
	buffer.nElements = this->nElements;

	return buffer;
}

//Non-Class Operators
UTF32String StdXX::operator+(const UTF32String &refLeft, const UTF32String &refRight)
{
	UTF32String tmp;

	tmp.EnsureCapacity(refLeft.GetLength() + refRight.GetLength());
	tmp += refLeft;
	tmp += refRight;

	return tmp;
}

bool StdXX::operator<(const UTF32String &refLeft, const UTF32String &refRight)
{
	int32 cmp;

	if(refLeft.GetLength() < refRight.GetLength())
	{
		cmp = MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refLeft.GetSize());

		return cmp ? cmp < 0 : true;
	}
	else if(refLeft.GetLength() > refRight.GetLength())
	{
		cmp = MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refRight.GetSize());

		return cmp ? cmp < 0 : false;
	}

	return MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refLeft.GetSize()) < 0;
}

bool StdXX::operator>(const UTF32String &refLeft, const UTF32String &refRight)
{
	int32 cmp;

	if(refLeft.GetLength() < refRight.GetLength())
	{
		cmp = MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refLeft.GetSize());

		return cmp ? cmp > 0 : false;
	}
	else if(refLeft.GetLength() > refRight.GetLength())
	{
		cmp = MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refRight.GetSize());

		return cmp ? cmp > 0 : true;
	}

	return MemCmp(refLeft.GetC_Str(), refRight.GetC_Str(), refLeft.GetSize()) > 0;
}