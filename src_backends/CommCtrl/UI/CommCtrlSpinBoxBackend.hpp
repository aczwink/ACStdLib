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
//Local
#include <Std++/_Backends/UI/SpinBoxBackend.hpp>
#include <Std++/UI/Controls/SpinBox.hpp>
#include "CommCtrlWidgetBackend.hpp"
#include "Win32Window.hpp"

namespace _stdxx_
{
	/*
	WinAPI Documentation: https://msdn.microsoft.com/en-us/library/windows/desktop/bb759880(v=vs.85).aspx
	*/
	class CommCtrlSpinBoxBackend : public SpinBoxBackend, public CommCtrlWidgetBackend
	{
	public:
		//Constructor
		inline CommCtrlSpinBoxBackend(StdXX::UIBackend& uiBackend, StdXX::UI::SpinBox *spinBox)
			: SpinBoxBackend(uiBackend), CommCtrlWidgetBackend(uiBackend), WidgetBackend(uiBackend),
			spinBox(spinBox), editControl(*this, WC_EDITW, ES_NUMBER | ES_RIGHT, WS_EX_CLIENTEDGE), upDownControl(*this, UPDOWN_CLASSW, UDS_ALIGNRIGHT | UDS_ARROWKEYS | UDS_HOTTRACK | UDS_SETBUDDYINT)
		{
			this->upDownControl.SendMessage(UDM_SETBUDDY, (WPARAM)this->editControl.GetHWND(), 0);
		}

		//Methods
		StdXX::Math::SizeD GetSizeHint() const override;
		StdXX::UI::Widget & GetWidget() override;
		const StdXX::UI::Widget & GetWidget() const override;
		void OnMessage(WinMessageEvent& event) override;
		void SetBounds(const StdXX::Math::RectD &bounds) override;
		void SetEnabled(bool enable) override;
		void SetRange(int32 min, int32 max) override;
		void SetValue(int32 value) override;
		void Show(bool visible) override;

		// not implemented
		void Repaint() override;
		void SetEditable(bool enable) const override;

	private:
		//Members
		StdXX::UI::SpinBox *spinBox;
		Win32Window editControl;
		Win32Window upDownControl;
	};
}