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
//corresponding header
#include "../../headers/Debug.h"
//Global
#include <Windows.h>
//Local
#include "../../headers/Containers/Strings/CString.h"
#include "../../headers/Containers/Strings/String.h"

#ifdef _DEBUG
void ACStdLib::AssertionFailed(const char *pContext, const CString &refMessage, const char *pFileName, uint32 lineNumber, const char *pFunctionName)
{
	CString message;
	CUTF16String msg16;

	message = "Expression: ";
	message += pContext;
	message += "\n";
	message += refMessage;
	message += "\nFile: ";
	message += pFileName;
	message += " (" + ToString((uint64)lineNumber) + ")\nFunction: ";
	message += pFunctionName;

	msg16 = message.GetUTF16();
	MessageBoxW(NULL, (LPCWSTR)msg16.GetC_Str(), L"Assertion", MB_ICONERROR | MB_TASKMODAL);
	abort();
}
#endif