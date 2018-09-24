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
#include "CommCtrlSliderBackend.hpp"
//Local
#include <Std++/UI/Controls/Slider.hpp>
//Namespaces
using namespace _stdxx_;
using namespace StdXX::Math;
using namespace StdXX::UI;

//Public methods
SizeD CommCtrlSliderBackend::GetSizeHint() const
{
	//TODO: min width
	//TODO: this seems to be working... dont known how it is with different fonts

	return SizeD(40, 26);
}

Widget &CommCtrlSliderBackend::GetWidget()
{
	return *this->slider;
}

const Widget &CommCtrlSliderBackend::GetWidget() const
{
	return *this->slider;
}

void CommCtrlSliderBackend::SetPosition(uint32 pos)
{
	this->SendMessage(TBM_SETPOS, TRUE, pos);
}

void CommCtrlSliderBackend::SetRange(uint32 min, uint32 max)
{
	this->SendMessage(TBM_SETRANGE, TRUE, MAKELONG(min, max));
}






//not implemented
void _stdxx_::CommCtrlSliderBackend::Repaint()
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void _stdxx_::CommCtrlSliderBackend::Select(StdXX::UI::ControllerIndex & controllerIndex) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void _stdxx_::CommCtrlSliderBackend::SetEditable(bool enable) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void _stdxx_::CommCtrlSliderBackend::SetHint(const StdXX::String & text) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void _stdxx_::CommCtrlSliderBackend::Show(bool visible)
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

void _stdxx_::CommCtrlSliderBackend::UpdateSelection(StdXX::UI::SelectionController & selectionController) const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}

uint32 _stdxx_::CommCtrlSliderBackend::GetPosition() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
	return uint32();
}

void _stdxx_::CommCtrlSliderBackend::ResetView() const
{
	NOT_IMPLEMENTED_ERROR; //TODO: implement me
}