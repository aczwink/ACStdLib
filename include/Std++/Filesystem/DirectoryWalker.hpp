/*
 * Copyright (c) 2018 Amir Czwink (amir130@hotmail.de)
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
#include "Directory.hpp"
#include "DirectoryIterator.hpp"
#include "File.hpp"

namespace StdPlusPlus
{
	class DirectoryWalker
	{
		struct WalkerState
		{
			AutoPointer<const Directory> directory;
			AutoPointer<DirectoryIterator> iterator;

			inline WalkerState()
			{
			}

			inline WalkerState(AutoPointer<const Directory> &&directory, AutoPointer<DirectoryIterator> &&iterator)
			{
				this->directory = Move(directory);
				this->iterator = Move(iterator);
			}

			inline WalkerState(WalkerState &&rhs)
			{
				this->directory = Move(rhs.directory);
				this->iterator = Move(rhs.iterator);
			}

			inline WalkerState &operator=(WalkerState &&rhs)
			{
				this->directory = Move(rhs.directory);
				this->iterator = Move(rhs.iterator);

				return *this;
			}

			inline WalkerState &operator=(const WalkerState &rhs)
			{
				this->directory = rhs.directory;
				this->iterator = rhs.iterator;

				return *this;
			}

			inline bool operator==(const WalkerState &rhs) const
			{
				return this->directory == rhs.directory && *this->iterator == *rhs.iterator;
			}
		};
	public:
		//Constructor
		inline DirectoryWalker(AutoPointer<const Directory> directory)
		{
			this->AddState(directory);
			this->CorrectIteratorPos();
		}

		//Inline operators
		inline bool operator==(const DirectoryWalker &rhs) const
		{
			if(this->states.IsEmpty())
				return rhs.states.IsEmpty();
			if(rhs.states.IsEmpty())
				return false;

			return this->states.Last() == rhs.states.Last();
		}

		inline bool operator!=(const DirectoryWalker &rhs) const
		{
			return !(*this == rhs);
		}

		inline AutoPointer<File> operator*()
		{
			return (*(*this->states.Last().iterator)).Cast<File>();
		}

		inline DirectoryWalker &operator++() //Prefix++
		{
			this->states.Last().iterator->operator++();
			this->CorrectIteratorPos();
			return *this;
		}

	private:
		//Members
		LinkedList<WalkerState> states;

		//Methods
		void CorrectIteratorPos();

		//Inline
		inline void AddState(AutoPointer<const Directory> directory)
		{
			if(!directory.IsNull())
			{
				DirectoryIterator it = directory->begin();
				this->states.InsertTail(WalkerState(Move(directory), new DirectoryIterator(Move(it))));
			}
		}
	};

	class DirectoryWalkerWrapper
	{
	public:
		//Constructor
		inline DirectoryWalkerWrapper(AutoPointer<const Directory> directory) : directory(directory)
		{
		}

		//For range-based loop
		inline DirectoryWalker begin() const
		{
			return DirectoryWalker(this->directory);
		}

		inline DirectoryWalker end() const
		{
			return DirectoryWalker(nullptr);
		}

	private:
		//Members
		AutoPointer<const Directory> directory;
	};
}