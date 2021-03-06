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
#pragma once
//Local
#include "SeekableInputStream.hpp"

namespace StdXX
{
    class STDPLUSPLUS_API BufferInputStream : public SeekableInputStream
    {
    private:
        //Variables
        const byte *pStart;
        const byte *current;
        const byte *endPos;
    public:
        //Constructor
        BufferInputStream(const void *pBuffer, uint32 size);

        //Methods
        uint32 GetBytesAvailable() const override;
        uint64 QueryCurrentOffset() const override;
        uint64 QueryRemainingBytes() const override;
        uint64 QuerySize() const override;
        bool IsAtEnd() const override;
        uint32 ReadBytes(void *pDestination, uint32 count) override;
        void SeekTo(uint64 offset) override;
        uint32 Skip(uint32 nBytes) override;
    };
}