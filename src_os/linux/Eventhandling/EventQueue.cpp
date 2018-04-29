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
#include <Std++/Eventhandling/EventQueue.hpp>
//Global
#include <poll.h>
//Namespaces
using namespace StdPlusPlus;
//Definitions
#define THIS ((DynamicArray<pollfd> *)this->internal)

//Private methods
void EventQueue::System_CollectWaitObjects()
{
	THIS->Resize(0);

	auto collector = [this](_stdpp::WaitObjHandle waitObjHandle, bool input)
	{
		pollfd pfd;
		pfd.fd = waitObjHandle.fd;
		pfd.events = static_cast<short>(input ? POLLIN : POLLOUT);

		THIS->Push(pfd);
	};

	for(const EventSource *const& source : this->sources)
	{
		source->VisitWaitObjects(collector);
	}
}

void EventQueue::System_Init()
{
	this->internal = new DynamicArray<pollfd>;
}

void EventQueue::System_Shutdown()
{
	delete THIS;
}

void EventQueue::System_WaitForEvents(uint64 timeOut)
{
	timespec waitTime;

	waitTime.tv_sec = static_cast<__time_t>(timeOut / 1000000);
	waitTime.tv_nsec = static_cast<__syscall_slong_t>((timeOut % 1000000) * 1000);


	ppoll(&(*THIS)[0], THIS->GetNumberOfElements(), &waitTime, nullptr);
}