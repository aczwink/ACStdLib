/*
 * Copyright (c) 2021 Amir Czwink (amir130@hotmail.de)
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

namespace StdXX
{
	template<typename EnumType, typename EncodedType = typename Type::UnderlyingType<EnumType>::type>
	class Flags
	{
	public:
		//Members
		EncodedType encodedFlags;

		//Constructors
		inline Flags() : encodedFlags()
		{
		}

		inline Flags(EnumType flag) : encodedFlags(static_cast<EncodedType>(flag))
		{
		}

		inline Flags(EncodedType encodedFlags) : encodedFlags(encodedFlags)
		{
		}

		//Operators
		bool operator==(const Flags<EnumType, EncodedType>&) const = default;

		//Inline
		inline bool IsSet(EnumType value) const
		{
			return (this->encodedFlags & static_cast<EncodedType>(value)) != 0;
		}

		inline void SetFlag(EnumType flag)
		{
			this->encodedFlags |= static_cast<EncodedType>(flag);
		}

		inline Flags WithFlag(EnumType flag) const
		{
			return this->encodedFlags | static_cast<EncodedType>(flag);
		}
	};
}