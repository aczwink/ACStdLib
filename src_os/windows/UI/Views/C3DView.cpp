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
#include "../../../../headers/UI/Views/C3DView.h"
//Global
#include <Windows.h>
//Local
#include "../../../../headers/Rendering/CDeviceContext.h"
#include "../CFullAccessWidget.h"
#include "../Definitions.h"
//Namespaces
using namespace ACStdLib;
using namespace ACStdLib::UI;

//Private methods
void C3DView::CreateOSWindow()
{
	this->pOSHandle = CreateWindowExW(0, ACSTDLIB_WIN_WNDCLASS, nullptr, WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, GET_HWND(this->GetParent()->GetWindow()), nullptr, GetModuleHandle(nullptr), nullptr);
	SetWindowLongPtr((HWND)this->pOSHandle, GWLP_USERDATA, (LONG_PTR)this);
}