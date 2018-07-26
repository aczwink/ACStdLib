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
#include <Std++/_Backends/UI/SliderBackend.hpp>
#include "../Widget.hpp"

namespace StdXX
{
    namespace UI
    {
        class STDPLUSPLUS_API Slider : public Widget
        {
        public:
			//Dynamic event handlers
			Function<void()> onValueChangedHandler;

            //Constructor
            Slider();

			//Inline
			inline uint32 GetPosition() const
			{
				return this->backend->GetPosition();
			}

			inline void SetPosition(uint32 pos)
			{
				this->sliderBackend->SetPosition(pos);
			}

			inline void SetRange(uint32 min, uint32 max) const
			{
				this->sliderBackend->SetRange(min, max);
			}

		private:
        	//Members
        	_stdxx_::SliderBackend *sliderBackend;
        };
    }
}