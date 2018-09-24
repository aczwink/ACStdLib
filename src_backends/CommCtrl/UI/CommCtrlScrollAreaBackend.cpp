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
#include "CommCtrlScrollAreaBackend.hpp"
//Namespaces
using namespace _stdxx_;
using namespace StdXX::Math;
using namespace StdXX::UI;

//Public methods
WidgetContainerBackend* CommCtrlScrollAreaBackend::CreateContentAreaBackend(CompositeWidget & widget)
{
	return nullptr;
}

SizeD CommCtrlScrollAreaBackend::GetSizeHint() const
{
	//TODO: actually sizes of both scroll bars...
	return SizeD(); //no requirements
}






















//Not implemented:
void _stdxx_::CommCtrlScrollAreaBackend::Repaint()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::SetBounds(const StdXX::Math::RectD & bounds)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::SetEditable(bool enable) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::SetEnabled(bool enable)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::SetHint(const StdXX::String & text) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::Show(bool visible)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::IgnoreEvent()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::ResetView() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::Select(StdXX::UI::ControllerIndex & controllerIndex) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

void _stdxx_::CommCtrlScrollAreaBackend::UpdateSelection(StdXX::UI::SelectionController & selectionController) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
}

StdXX::Math::RectD _stdxx_::CommCtrlScrollAreaBackend::GetContentAreaBounds() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implementme
	return StdXX::Math::RectD();
}