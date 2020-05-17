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
#pragma once
//Local
#include <Std++/Containers/Array/DynamicArray.hpp>
#include <Std++/Containers/Strings/String.hpp>
#include <Std++/Tuple.hpp>

namespace StdXX
{
	namespace Math
	{
		/**
		 * Does include 0, such that a semiring is formed.
		 */
		class STDPLUSPLUS_API Natural
		{
		public:
			//Constructor
			/**
			 * Inits the value to zero.
			 */
			inline Natural() = default;
			inline Natural(const Natural& other) = default;
			inline Natural(Natural&& other) = default;

			inline Natural(uint64 v)
			{
				if (v != 0)
				{
					this->value.Resize(1);
					this->value[0] = v;
				}
			}

			//Properties
			inline uint64 RoundDown() const
			{
				if(this->value.IsEmpty())
					return 0;
				if(this->value.GetNumberOfElements() > 1)
					return Unsigned<uint64>::Max();
				return this->value[0];
			}

			//Assignment operators
			Natural& operator=(const Natural& other) = default;
			Natural& operator=(Natural&& other) = default;
			
			//Arithmetic operators
			Natural operator+(const Natural& other) const;
			Natural operator-(const Natural& other) const;
			Natural operator*(const Natural& other) const;
			
			inline Natural operator/(const Natural& other) const
			{
				return this->DivMod(other).Get<0>();
			}
			
			inline Natural& operator+=(const Natural& other)
			{
				*this = *this + other;
				return *this;
			}

			inline Natural& operator-=(const Natural& other)
			{
				*this = *this - other;
				return *this;
			}

			inline Natural& operator*=(const Natural& other)
			{
				*this = *this * other;
				return *this;
			}

			inline Natural& operator/=(const Natural& other)
			{
				*this = *this / other;
				return *this;
			}

			inline Natural& operator++() //pre-increment
			{
				*this += 1;
				return *this;
			}

			//Binary operators
			Natural operator<<(uint64 shift) const;

			inline Natural& operator<<=(uint64 shift)
			{
				*this = (*this) << shift;
				return *this;
			}

			//Comparison operators
			bool operator<(const Natural& other) const;
			bool operator<=(const Natural& other) const;

			inline bool operator==(const Natural& other) const
			{
				return this->value == other.value;
			}

			inline bool operator!=(const Natural& other) const
			{
				return this->value != other.value;
			}

			inline bool operator>=(const Natural& other) const
			{
				return other <= *this;
			}

			//Methods
			Tuple<Natural, Natural> DivMod(const Natural& divisor) const;
			String ToString() const;

		private:
			//Members
			DynamicArray<uint64> value;
		};
	}
}