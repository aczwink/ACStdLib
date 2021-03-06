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
#include <Std++/Definitions.h>
#include <Std++/Unsigned.hpp>

namespace StdXX
{
	namespace UI
	{
		//Move declarations
		class TreeController;

		class ControllerIndex
		{
			friend class TreeController;
		public:
			//Constructor
			inline ControllerIndex() : treeController(nullptr)
			{
				this->row = Unsigned<uint32>::Max();
				this->column = Unsigned<uint32>::Max();
				this->modelNode = nullptr;
			}

			//Operators
			inline bool operator==(const ControllerIndex &other) const
			{
				return this->row == other.row && this->column == other.column && this->modelNode == other.modelNode;
			}

			inline bool operator!=(const ControllerIndex &other) const
			{
				return !((*this) == other);
			}

			//Methods
			ControllerIndex GetParent() const;

			//Inline
			inline uint32 GetColumn() const
			{
				return this->column;
			}

			inline const void* GetNode() const
			{
				return this->modelNode;
			}

			inline uint32 GetRow() const
			{
				return this->row;
			}

			inline bool HasParent() const
			{
				return (*this) != ControllerIndex();
			}

		private:
			//Members
			uint32 row;
			uint32 column;
			/**
			 * The node from the real data model tree.
			 */
			const void *modelNode;
			const TreeController *treeController;

			//Constructor
			inline ControllerIndex(uint32 row, uint32 column, const void *modelNode, const TreeController *treeController) : treeController(treeController)
			{
				this->row = row;
				this->column = column;
				this->modelNode = modelNode;
			}
		};
	}
}