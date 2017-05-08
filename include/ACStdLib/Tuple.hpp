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
#include "Definitions.h"

namespace ACStdLib
{
    //Forward declarations
    template<typename... ElementTypes>
    class Tuple;
}

namespace _ACIntern
{
    //Tuple element type evaluator
    template <uint32 idx, typename Tuple>
    struct TupleElementType;

    template<typename FirstType, typename... RestTypes>
    struct TupleElementType<0, ACStdLib::Tuple<FirstType, RestTypes...>>
    {
        typedef FirstType ValueType;
        typedef ACStdLib::Tuple<FirstType, RestTypes...> TupleType;
    };

    template<uint32 index, typename FirstType, typename... RestTypes>
    struct TupleElementType<index, ACStdLib::Tuple<FirstType, RestTypes...>> : public TupleElementType<index - 1, ACStdLib::Tuple<RestTypes...>>
    {
    };
}

namespace ACStdLib
{
    template<>
    class Tuple<> //empty tuple
    {
    protected:
        //Constructor
        inline Tuple() //forbid empty tuple
        {
        }

        //Inline
        inline void Set()
        {
        }
    };

    template<typename FirstType, typename... RestTypes>
    class Tuple<FirstType, RestTypes...> : private Tuple<RestTypes...>
    {
	public:
		//Members
		FirstType element;

        //Constructors
        inline Tuple()
        {
        }

        inline Tuple(const FirstType &refFirst, const RestTypes &... refRest) : Tuple<RestTypes...>(static_cast<const RestTypes &>(refRest)...), element(refFirst)
        {
        }

        inline Tuple(FirstType &&refFirst, RestTypes &&... refRest) : Tuple<RestTypes...>(static_cast<RestTypes &&>(refRest)...), element(refFirst)
        {
        }

        //Inline
        template < uint32 idx>
        inline const typename _ACIntern::TupleElementType<idx, Tuple<FirstType, RestTypes...>>::ValueType &Get() const
        {
            return static_cast<const typename _ACIntern::TupleElementType<idx, Tuple<FirstType, RestTypes...>>::TupleType *>(this)->element;
        }

        template<uint32 idx>
        inline void Set(const typename _ACIntern::TupleElementType<idx, Tuple<FirstType, RestTypes...>>::ValueType &&refNewValue)
        {
            static_cast<typename _ACIntern::TupleElementType<idx, Tuple<FirstType, RestTypes...>>::TupleType *>(this)->element = refNewValue;
        }

        inline void Set(const FirstType &refFirst, const RestTypes &... refRest)
        {
            this->element = refFirst;
            Tuple<RestTypes...>::Set(static_cast<RestTypes &&>(refRest)...);
        }
    };
}