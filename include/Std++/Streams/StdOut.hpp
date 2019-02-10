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
#include "OutputStream.hpp"

namespace StdXX
{
    class CAutoLineBreaker
    {
    private:
        //Members
        OutputStream &refOutput;

    public:
        //Constructor
        inline CAutoLineBreaker(OutputStream &refOutput) : refOutput(refOutput)
        {
        }

        //Destructor
        inline ~CAutoLineBreaker()
        {
            this->refOutput << endl;
        }

        //Inline
        inline CAutoLineBreaker &operator<<(const OldString &refString)
        {
            this->refOutput << refString;
            return *this;
        }
    };

    class StdErr : public OutputStream
    {
    public:
        //Methods
        void WriteByte(byte b);
        uint32 WriteBytes(const void *pSource, uint32 size);

        void Flush() override;
    };

    class StdOut : public OutputStream
    {
    public:
        //Methods
        void WriteByte(byte b);
        uint32 WriteBytes(const void *pSource, uint32 size);

        void Flush() override;
    };

    //Global Instances
    extern StdErr STDPLUSPLUS_API stdErr;
    extern StdOut STDPLUSPLUS_API stdOut;
}