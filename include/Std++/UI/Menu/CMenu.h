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
#pragma once
//Local
#include "../../Containers/Array/DynamicArray.hpp"
#include "../../Containers/Strings/OldString.hpp"

namespace StdPlusPlus
{
    namespace UI
    {
        //Forward declarations
        class CAction;

        class AMenuEntry
        {
        };

        class CActionEntry : public AMenuEntry
        {
        public:
            //Members
            CAction &refAction;

            //Constructor
            inline CActionEntry(CAction &refAction) : refAction(refAction)
            {
            }
        };

        class STDPLUSPLUS_API CMenu : public AMenuEntry
        {
            friend class CMenuBar;
        private:
            //Members
            void *pOSHandle;
            DynamicArray<AMenuEntry *> menuEntries;

            //Methods
            void AppendItemOS(CActionEntry *pEntry);
            void DestructOS();

        public:
            //Constructor
            CMenu(const OldString &refText);

            //Destructor
            ~CMenu();

            //Methods
            void AppendItem(CAction &refAction);
            void AppendSeperator();
            void AppendSubMenu(CMenu *pSubMenu);
        };
    }
}