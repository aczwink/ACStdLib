/*
 * Copyright (c) 2018 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/Containers/FIFOBuffer.hpp>
//Namespaces
using namespace StdPlusPlus;

//Constructor
FIFOBuffer::FIFOBuffer()
{
	this->pCurrentFront = NULL;
	this->pCurrentTail = NULL;
	this->atEnd = false;
	this->SetAllocationInterval(1024);
}

void FIFOBuffer::EnsureCapacity(uint32 requiredNumberOfElements)
{
	uint32 offsetToFront, offsetTail;

	ASSERT(requiredNumberOfElements > this->GetEnd() - this->data, u8"If you see this, report to Std++");

	offsetToFront = (uint32)(this->pCurrentFront - this->data);
	offsetTail = (uint32)(this->pCurrentTail - this->data);

	ResizeableSequenceContainer<byte>::EnsureCapacity(requiredNumberOfElements);

	this->pCurrentFront = this->data + offsetToFront;
	this->pCurrentTail = this->data + offsetTail;
}

bool FIFOBuffer::IsAtEnd() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return false;
}

uint32 FIFOBuffer::PeekBytes(void *destination, uint32 offset, uint32 count) const
{
	const byte *at = this->pCurrentFront + offset;
	if(at + count > this->pCurrentTail)
		count = static_cast<uint32>(this->pCurrentTail - at);

	MemCopy(destination, at, count);

	return count;
}

uint32 FIFOBuffer::ReadBytes(void *destination, uint32 count)
{
	count = this->PeekBytes(destination, 0, count);
	this->pCurrentFront += count;
	this->nElements -= count;
	if(this->pCurrentFront == this->pCurrentTail)
		this->atEnd = true;

	return count;
}

void FIFOBuffer::Release()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

uint32 FIFOBuffer::Skip(uint32 nBytes)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return 0;
}

uint32 FIFOBuffer::WriteBytes(const void *pSource, uint32 count)
{
	this->EnsureStorage(count);

	ASSERT(this->pCurrentTail + count <= this->GetEnd(), u8"If you see this, report to Std++");

	MemCopy(this->pCurrentTail, pSource, count);
	this->pCurrentTail += count;
	this->nElements += count;

	return count;
}

//Private methods
void FIFOBuffer::EnsureStorage(uint32 requiredAdditionalSize)
{
	uint32 offsetToFront, offsetToEnd, spaceBack;

	//we read from the front and write to the back
	offsetToFront = (uint32)(this->pCurrentFront - this->data);
	offsetToEnd = (uint32)(this->pCurrentTail - this->data);
	spaceBack = (uint32)(this->GetEnd() - this->pCurrentTail);

	//check if we have enough space at the back
	if(spaceBack < requiredAdditionalSize)
	{
		//check if we have enough place at front+back, but with some threshold to not always copy when only few bytes are free
		if(offsetToFront + spaceBack < requiredAdditionalSize || offsetToFront+spaceBack < this->capacity / 8)
		{
			this->EnsureAdditionalCapacity(requiredAdditionalSize);
		}
		else
		{
			//move to front
			MemCopy(this->data, this->pCurrentFront, this->GetRemainingBytes());
			this->pCurrentFront = this->data;
			this->pCurrentTail = this->data + offsetToEnd - offsetToFront;
		}
	}
}