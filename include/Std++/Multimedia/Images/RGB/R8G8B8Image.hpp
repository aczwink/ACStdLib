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
#include "../RGBImage.hpp"

namespace StdXX
{
    namespace Multimedia
    {
        class STDPLUSPLUS_API R8G8B8Image : public RGBImage
        {
        private:
            //Members
            byte *pRedChannel;
            byte *pGreenChannel;
            byte *pBlueChannel;
        public:
            //Constructor
            R8G8B8Image(uint16 width, uint16 height);

            //Destructor
            ~R8G8B8Image();

            //Derived methods
            using RGBImage::SetPixel;

            //Methods
            void GetPixel(uint32 index, byte &refR, byte &refG, byte &refB) const;
            void SetPixel(uint32 index, byte r, byte g, byte b);

            //Inline
            inline byte *GetBlueChannel()
            {
                return this->pBlueChannel;
            };

            inline byte *GetGreenChannel()
            {
                return this->pGreenChannel;
            };

            inline byte *GetRedChannel()
            {
                return this->pRedChannel;
            };
        };
    }
}