/*
 * Copyright (c) 2019 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/Containers/Strings/String.hpp>
#include <Std++/Color.hpp>

namespace StdXX
{
	namespace UI
	{
		class StyleValue
		{
		public:
			//Constructors
			inline StyleValue()
			{
			}

			inline StyleValue(const String& string) : string(string)
			{
			}

			inline StyleValue(const Color& color) : color(color)
			{
			}

			inline StyleValue(float64 number) : number(number)
			{
			}

			//Properties
			inline const StdXX::Color& Color() const
			{
				return this->color;
			}

			inline float64 Number() const
			{
				return this->number;
			}

		private:
			//Members
			String string;
			StdXX::Color color;
			float64 number;
		};
	}
}