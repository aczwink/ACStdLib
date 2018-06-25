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
#pragma once
//Local
#include "../Definitions.h"
#include <Std++/Debug.hpp>
#include <Std++/Mathematics.hpp>
#include <Std++/Containers/Strings/String.hpp>

namespace StdPlusPlus
{
	/**
	* Represents dates within the Gregorian calendar.
	*
	* This class can represent invalid dates but refuses errornous ones (see method descriptions).
	*/
	class STDPLUSPLUS_API Date
	{
	public:
		//Constructors
		/**
		* Constructs the date '0000-00-00'
		*/
		inline Date() : year(0), month(0), day(0)
		{
		}

		inline Date(int64 year, uint8 month = 0, uint8 day = 0) : year(year), month(month), day(day)
		{
			this->CheckForErrornous();
		}

		//Functions
		static uint8 GetNumberOfDaysInMonth(uint8 month, int64 year);
		static bool IsLeapYear(int64 year);

		//Inline
		inline bool IsValid() const
		{
			return (this->year != 0) &&
				Math::IsValueInInterval(this->month, uint8(1), uint8(12)) &&
				Math::IsValueInInterval(this->day, uint8(1), uint8(this->GetNumberOfDaysInMonth(this->month, this->year)));
		}
		
		/**
		* Format date according to ISO 8601 i.e. "YYYY-MM-DD".
		*/
		inline String ToISOString() const
		{
			return String::Number(this->year, 10, 4) + u8"-" + String::Number(this->month, 10, 2) + u8"-" + String::Number(this->day, 10, 2);
		}

	private:
		//Members
		int64 year;
		uint8 month;
		uint8 day;

		//Inline
		/**
		* An errornous date is in general one where at least one of the following conditions fail:
		* - The month is <= 12
		* - The day is <= the allowed number of days for the month.
		*
		* There is a special case, where year = 0 and month = 2. In this case the value of 29 is allowed.
		*/
		inline void CheckForErrornous() const
		{
			if (this->year == 0 && this->month == 2)
				ASSERT(this->day <= 29, u8"Errornous date")
			else
				ASSERT((this->month <= 12) && (this->day <= this->GetNumberOfDaysInMonth(this->month, this->year)), u8"Errornous date")
		}
	};
}