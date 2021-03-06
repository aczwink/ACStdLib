/*
 * Copyright (c) 2017-2019 Amir Czwink (amir130@hotmail.de)
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
//Corresponding header
#include <Std++/UI/CommonDialogs.hpp>
//Global
#include <gtk/gtk.h>
//Local
#include "../Gtk.h"
//Namespaces
using namespace StdXX;
using namespace StdXX::UI;

//Namespace functions
Path CommonDialogs::OpenFile(const Window &refParentWnd, const OldString &refTitle, const LinkedList<Tuple<OldString, OldString>> &filters, const Path &directory)
{
    gint result;
    UTF8String titleUTF8;

    titleUTF8 = refTitle.GetUTF16();
    GtkWidget *fileChooserDialog = gtk_file_chooser_dialog_new((gchar *)titleUTF8.GetC_Str(), GTK_WINDOW(PRIVATE_DATA(&refParentWnd)->widget), GTK_FILE_CHOOSER_ACTION_OPEN, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, nullptr);
    GtkFileChooser *fileChooser = GTK_FILE_CHOOSER(fileChooserDialog);

	if(!directory.GetString().IsEmpty())
	{
		gtk_file_chooser_set_current_folder(fileChooser, reinterpret_cast<const gchar *>(directory.GetString().ToUTF8().GetRawZeroTerminatedData()));
	}

	for(auto &entry : filters)
	{
		GtkFileFilter *filter = gtk_file_filter_new();

		UTF8String pattern = entry.Get<1>().GetUTF16();
		UTF8String name = (entry.Get<0>() + " (" + pattern + ")").GetUTF16();

		gtk_file_filter_set_name(filter, (const gchar *)name.GetC_Str());
		gtk_file_filter_add_pattern(filter, (const gchar *)pattern.GetC_Str());

		gtk_file_chooser_add_filter(fileChooser, filter);
	}

    result = gtk_dialog_run(GTK_DIALOG(fileChooserDialog));
	String fileName;
    if(result == GTK_RESPONSE_ACCEPT)
    {
        char *pFileName;

        pFileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserDialog));
        fileName = String::CopyRawString(pFileName);

        g_free(pFileName);
    }

    gtk_widget_destroy(fileChooserDialog);

    return fileName;
}