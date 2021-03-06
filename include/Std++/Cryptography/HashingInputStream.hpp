/*
 * Copyright (c) 2018-2019,2021 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/SmartPointers/UniquePointer.hpp>
#include <Std++/Utility.hpp>
#include "Std++/Streams/InputStream.hpp"
#include "HashFunction.hpp"

namespace StdXX::Crypto
{
	/**
	 * This stream takes an underlying stream and returns its data as is.
	 * However, all data that passes this stream is piped through a hasher.
	 * The hash value can then be easily retrieved at any state.
	 * This is more convenient because when processing the underlying stream you probably want to skip data for example,
	 * however still need it because of the hash value.
	 */
	class STDPLUSPLUS_API HashingInputStream : public InputStream
	{
	public:
		//Constructor
		inline HashingInputStream(InputStream &inputStream, HashFunction* hasher) : inputStream(inputStream)
		{
			this->hasher = hasher;
		}

		//Methods
		uint32 GetBytesAvailable() const override;
		bool IsAtEnd() const override;
		uint32 ReadBytes(void *destination, uint32 count) override;
		uint32 Skip(uint32 nBytes) override;

	private:
		//Members
		InputStream &inputStream;
		HashFunction* hasher;
	};
}