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
#pragma once
//Local
#include <ACStdLib/Definitions.h>

namespace ACStdLib
{
    //Forward declarations
    class UTF8String;

    class ACSTDLIB_API CConstUTF8StringIterator
    {
    private:
        //Members
        const UTF8String &refString;
        const byte *pCurrent;
    public:
        //Constructor
        CConstUTF8StringIterator(const UTF8String &refString, uint32 index = 0);

        //Operators
        CConstUTF8StringIterator &operator++(); //Prefix ++
        uint32 operator*() const;

        //Inline Operators
        inline bool operator!=(const CConstUTF8StringIterator &refOther) const
        {
            return (&this->refString != &refOther.refString) || (this->pCurrent != refOther.pCurrent);
        }
    };
}