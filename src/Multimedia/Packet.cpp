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
//Class header
#include <Std++/Multimedia/Packet.hpp>
//Local
#include <Std++/Memory.hpp>
#include <Std++/Unsigned.hpp>
//Namespaces
using namespace StdXX;
using namespace StdXX::Multimedia;

//Constructors
Packet::Packet()
{
	this->data = nullptr;
	this->size = 0;
	this->capacity = 0;

	this->streamIndex = Unsigned<uint32>::Max();
	this->dts = Unsigned<uint64>::Max();
	this->pts = Unsigned<uint64>::Max();
	this->duration = Unsigned<uint64>::Max();;
	this->containsKeyframe = false;
}

Packet::Packet(uint32 size) : Packet()
{
	this->Allocate(size);
}

//Destructor
Packet::~Packet()
{
	if(this->data)
		MemFree(this->data);
}

//Operators
Packet &Packet::operator=(const Packet &source)
{
	this->Allocate(source.GetSize());
	MemCopy(this->GetData(), source.GetData(), this->GetSize());

	this->CopyAttributesFrom(source);
	
	return *this;
}

Packet &Packet::operator=(Packet &&source)
{
	if (this->data)
		MemFree(this->data);

	//take data
	this->data = source.data;
	source.data = nullptr;

	//take sizes
	this->size = source.size;
	this->capacity = source.capacity;
	source.size = source.capacity = 0;
	
	this->CopyAttributesFrom(source);
	
	return *this;
}

//Public methods
void Packet::Allocate(uint32 size)
{
	if(size > this->capacity)
	{
		this->data = (byte *)MemRealloc(this->data, size);
		this->capacity = size;
	}

	this->size = size;
}

bool Packet::ContainsKeyFrame() const
{
	return this->containsKeyframe;
}

void Packet::CopyAttributesFrom(const Packet& p)
{
	this->streamIndex = p.streamIndex;
	this->dts = p.dts;
	this->pts = p.pts;
	this->duration = p.duration;
	this->containsKeyframe = p.containsKeyframe;
}

uint64 Packet::GetDecodeTimestamp() const
{
	return this->dts;
}

uint64 Packet::GetPresentationTimestamp() const
{
	return this->pts;
}

uint32 Packet::GetStreamIndex() const
{
	return this->streamIndex;
}