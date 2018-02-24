/*
 * Copyright (c) 2017-2018 Amir Czwink (amir130@hotmail.de)
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
//corresponding header
#include <Std++/Debug.h>
//Global
#include <iostream>
//Local
#include <Std++/Containers/Strings/String.hpp>
#include <Std++/Containers/Strings/StringUtil.h>
#include <Std++/Streams/CStdOut.h>
//Namespaces
using namespace StdPlusPlus;

#ifdef _DEBUG
//Prototypes
void ShutdownStdPlusPlus();

void StdPlusPlus::AssertionFailed(const char *pContext, const String &refMessage, const char *pFileName, uint32 lineNumber, const char *pFunctionName)
{
    String message;

    message = u8"Expression: ";
    message += String::CopyRawString(pContext);
    message += u8"\n";
    message += refMessage;
    message += u8"\nFile: ";
    message += String::CopyRawString(pFileName);
    message += u8" (" + String::Number(lineNumber) + u8")\nFunction: ";
    message += String::CopyRawString(pFunctionName);

    stdErr << message << endl;

	static bool shutdown = true;
	if(shutdown)
	{
		shutdown = false;
		ShutdownStdPlusPlus(); //call the shutdown function that will report memory leaks and so on
	}
    exit(1);
}
#endif