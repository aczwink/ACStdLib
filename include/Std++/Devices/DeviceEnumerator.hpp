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
#include "../_Backends/DeviceEnumeratorState.hpp"
#include "../SmartPointers/AutoPointer.hpp"
#include "../SmartPointers/UniquePointer.hpp"
#include "Device.hpp"

namespace StdXX
{
	class STDPLUSPLUS_API DeviceEnumerator
	{
	public:
		//Constructor
		DeviceEnumerator(DeviceType filter);

		//Inline
		inline AutoPointer<Device> GetNextDevice()
		{
			return this->state->GetNextDevice();
		}

	private:
		//Members
		UniquePointer<_stdxx_::DeviceEnumeratorState> state;
	};
}