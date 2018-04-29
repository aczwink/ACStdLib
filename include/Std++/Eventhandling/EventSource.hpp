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
#include <Std++/Definitions.h>
#include <Std++/Function.hpp>

namespace _stdpp
{
	union WaitObjHandle
	{
		void *handle;
		int fd;
	};
}

namespace StdPlusPlus
{
	class EventSource
	{
	public:
		//Destructor
		virtual ~EventSource() = default;

		//Abstract
		virtual void DispatchPendingEvents() = 0;

		/**
		 * Return the maximum time until this source expects a new event.
		 * Event queues will take this information to determine its sleeping duration.
		 *
		 * @return in nanoseconds
		 */
		virtual uint64 GetMaxTimeout() const = 0;

		virtual void VisitWaitObjects(const Function<void (_stdpp::WaitObjHandle, bool)> &visitFunc) const = 0;
	};
}