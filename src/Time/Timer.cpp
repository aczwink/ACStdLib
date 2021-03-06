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
#include <Std++/Time/Timer.hpp>
//Namespaces
using namespace StdXX;

//Constructor
Timer::Timer(const Function<void()> &timedOutCallback, TimerEventSource &eventSource) : eventSource(eventSource)
{
	this->timedOutCallback = timedOutCallback;
	this->isPending = false;
}

//Destructor
Timer::~Timer()
{
	this->Stop();
}

//Public methods
void Timer::OneShot()
{
	ASSERT_EQUALS(false, this->isPending);

	this->isPending = true;
	this->isPeriodic = false;
	this->eventSource.AddTimerToQueue(*this);
}

void Timer::Start()
{
	ASSERT_EQUALS(false, this->isPending);

	this->isPending = true;
	this->isPeriodic = true;
	this->eventSource.AddTimerToQueue(*this);
}

void Timer::Stop()
{
	this->isPending = false;
}