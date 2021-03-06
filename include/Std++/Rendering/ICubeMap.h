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
#include "ITexture.h"

namespace StdXX
{
    namespace Rendering
    {
        class STDPLUSPLUS_API ICubeMap : public ITexture
        {
        public:
            //Abstract
            virtual void SetBackTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
            virtual void SetBottomTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
            virtual void SetFrontTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
            virtual void SetLeftTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
            virtual void SetRightTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
            virtual void SetTopTexture(uint16 width, uint16 height, const void *pCompressedData) = 0;
        };
    }
}