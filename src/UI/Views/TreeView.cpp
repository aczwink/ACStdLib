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
//Class header
#include <Std++/UI/Views/TreeView.hpp>
//Local
#include <Std++/UI/WidgetContainer.hpp>
#include <Std++/UI/Controllers/TreeController.hpp>
//Namespaces
using namespace StdPlusPlus;
using namespace StdPlusPlus::UI;

//Constructor
TreeView::TreeView(WidgetContainer *pParent) : View(pParent)
{
    this->sizingPolicy.SetHorizontalPolicy(SizingPolicy::Policy::Expanding);
    this->sizingPolicy.SetVerticalPolicy(SizingPolicy::Policy::Expanding);

    this->backend = this->GetParentBackend()->CreateChildBackend(_stdpp::WindowBackendType::TreeView, this);
}

//Eventhandlers
void TreeView::OnModelChanged()
{
    this->backend->ClearView();
}

void TreeView::OnSelectionChanged()
{
	this->backend->UpdateSelection(this->selectionController);

	View::OnSelectionChanged();
}