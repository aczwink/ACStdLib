/*
 * Copyright (c) 2018-2020 Amir Czwink (amir130@hotmail.de)
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
#pragma once
//Class header
#include "ContentAreaWidgetBackend.hpp"
//Local
#include <Std++/Tuple.hpp>

//Forward declarations
namespace StdXX
{
	namespace UI
	{
		class Window;
	}
}

namespace _stdxx_
{
	class WindowBackend : public ContentAreaWidgetBackend
	{
	public:
		//Constructor
		inline WindowBackend(StdXX::UIBackend& uiBackend) : ContentAreaWidgetBackend(uiBackend)
		{
		}

		//Abstract
		virtual void Maximize() = 0;
		virtual StdXX::FileSystem::Path SelectExistingDirectory(const StdXX::String &title, const StdXX::Function<bool(StdXX::FileSystem::Path &)> callback) const = 0;
		virtual StdXX::FileSystem::Path SelectExistingFile(const StdXX::String &title, const StdXX::DynamicArray<StdXX::Tuple<StdXX::String, StdXX::DynamicArray<StdXX::String>>>& filters, const StdXX::FileSystem::Path& initialPath) const = 0;
		virtual void SetMenuBar(StdXX::UI::MenuBar *menuBar, MenuBarBackend *menuBarBackend) = 0;
		virtual void SetTitle(const StdXX::String &title) = 0;
		virtual void ShowErrorBox(const StdXX::String &title, const StdXX::String &message) const = 0;
		virtual void ShowInformationBox(const StdXX::String &title, const StdXX::String &message) const = 0;
	};
}