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
#include <Std++/_Backends/UI/CheckBoxBackend.hpp>
#include <Std++/UI/Controls/CheckBox.hpp>
#include "CommCtrlWidgetBackend.hpp"
#include "Win32Window.hpp"

namespace _stdxx_
{
	/*
	WinAPI Documentation: https://msdn.microsoft.com/de-de/library/windows/desktop/bb775943(v=vs.85).aspx
	*/
	class CommCtrlCheckBoxBackend : public CheckBoxBackend, public CommCtrlWidgetBackend, public Win32Window
	{
	public:
		//Constructor
		inline CommCtrlCheckBoxBackend(StdXX::UIBackend& uiBackend, StdXX::UI::CheckBox *checkBox)
			: CheckBoxBackend(uiBackend), CommCtrlWidgetBackend(uiBackend), WidgetBackend(uiBackend), Win32Window(*this, WC_BUTTONW, BS_AUTOCHECKBOX),
			checkBox(checkBox)
		{
		}

		//Methods
		StdXX::Math::SizeD GetSizeHint() const override;
		StdXX::UI::Widget & GetWidget() override;
		const StdXX::UI::Widget & GetWidget() const override;
		void OnMessage(WinMessageEvent& event) override;
		void SetText(const StdXX::String & text) override;
		void UpdateCheckState() override;

		//not implemented
		void Repaint() override;
		void SetEditable(bool enable) const override;

	private:
		//Members
		StdXX::UI::CheckBox *checkBox;
	};
}