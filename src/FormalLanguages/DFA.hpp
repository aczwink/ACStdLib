/*
 * Copyright (c) 2019 Amir Czwink (amir130@hotmail.de)
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
namespace _stdxx_
{
    template<typename InputSymbolType>
    class DFAState
    {
    };

    template<typename InputSymbolType>
    class DFA
    {
    public:
        //Destructor
        inline ~DFA()
        {
            for(DFAState<InputSymbolType> * const& prefState : states)
                delete prefState;
        }

        //Inline
        inline void AddState(DFAState<InputSymbolType>* state)
        {
            this->states.Insert(state);
        }

    private:
        //Members
        StdXX::BinaryTreeSet<DFAState<InputSymbolType> *> states;
    };
}