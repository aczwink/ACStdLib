/*
 * Copyright (c) 2017 Amir Czwink (amir130@hotmail.de)
 *
 * This file is part of ACStdLib.
 *
 * ACStdLib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ACStdLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ACStdLib.  If not, see <http://www.gnu.org/licenses/>.
 */
//Class header
#include <ACStdLib/Time/Timer.hpp>
//Local
#include "ACStdLib/Time/TimerScheduler.hpp"
//Namespaces
using namespace ACStdLib;

//Global variables
TimerScheduler g_scheduler;

//Public methods
void Timer::OneShot(uint32 timeOut_msec)
{
	g_scheduler.AddOneShotTimer(timeOut_msec * 1000, this);
}

void Timer::Stop()
{
	g_scheduler.RemoveOneShotTimer(this);
}