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
#include <ACStdLib/Multitasking/Thread.hpp>
//Global
#include <pthread.h>
//Local
#include <ACStdLib/Function.hpp>
//Namespaces
using namespace ACStdLib;

//Local functions
static void *RunThreadByFuncPointer(void *arg)
{
	return (void *) ((ThreadFunction)arg)();
}

static void *RunThreadByCFunction(void *arg)
{
	Function<int32()> *function = (Function<int32()> *)arg;
	int32 exitCode = (*function)();
	delete function;

	return (void *)exitCode;
}

//Constructors
Thread::Thread()
{
	pthread_t threadId;
	pthread_create(&threadId, nullptr, RunThreadByCFunction, new Function<int32()>(&Thread::ThreadMain, this));
	this->systemHandle = (void *) threadId;
}

Thread::Thread(ThreadFunction func)
{
	pthread_t threadId;
	pthread_create(&threadId, nullptr, RunThreadByFuncPointer, (void *)func);
	this->systemHandle = (void *) threadId;
}

//Destructor
Thread::~Thread()
{
}

//Public methods
void Thread::Join()
{
	pthread_join((pthread_t) this->systemHandle, nullptr);
}