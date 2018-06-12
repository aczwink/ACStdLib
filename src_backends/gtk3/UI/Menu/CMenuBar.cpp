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
#include <Std++/UI/Menu/CMenuBar.h>
//Global
#include <gtk/gtk.h>
//Local
#include <Std++/UI/Menu/CMenu.h>
#include "../Gtk.h"
//Namespaces
using namespace StdPlusPlus;
using namespace StdPlusPlus::UI;

//Constructor
CMenuBar::CMenuBar()
{
    this->pOSHandle = gtk_menu_bar_new();
    gtk_widget_show((GtkWidget *)this->pOSHandle); //default is show
}

//Private methods
void CMenuBar::AppendMenuOS(CMenu *pMenu)
{
    gtk_menu_shell_append(GTK_MENU_SHELL(this->pOSHandle), ((_AC_Gtk_Menu *)pMenu->pOSHandle)->pItem);
}

void CMenuBar::DestroyMenuOS()
{
}