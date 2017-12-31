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
#include "../../Definitions.h"
#include "ACStdLib/Containers/Strings/OldString.hpp"
#include "../Views/View.hpp"
#include "ControllerIndex.hpp"

namespace ACStdLib
{
    namespace UI
    {
		//Forward declarations
		class SelectionController;

        class ACSTDLIB_API TreeController
        {
            friend class View;
        public:
            //Destructor
            virtual ~TreeController() {}

            //Abstract
            virtual ControllerIndex GetChildIndex(uint32 row, uint32 column, const ControllerIndex &parent = ControllerIndex()) const = 0;
			virtual OldString GetColumnText(uint32 column) const = 0;
            virtual uint32 GetNumberOfChildren(const ControllerIndex &parent = ControllerIndex()) const = 0;
			/**
			 * A special value is the return value 0. This means that the controller does not provide data in relation with columns.
			 * In other words, the controller contains data but all ControllerIndex instances will have the column field invalid.
			 * This is useful when no column info should be provided in the corresponding views.
			 * For instance a simple ComboBox will have only a list of items without columns and column descriptions.
			 *
			 * @return
			 */
			virtual uint32 GetNumberOfColumns() const = 0;
            virtual OldString GetText(const ControllerIndex &index) const = 0;

            //Inline
            inline void ModelChanged()
            {
                if(this->view)
                    this->view->OnModelChanged();
            }

        protected:
            //Members
            View *view;

			//Inline
			inline ControllerIndex CreateIndex(uint32 row, uint32 column, void *node) const
			{
				return ControllerIndex(row, column, node);
			}

		private:
			//Eventhandlers
			virtual void OnSelectionChanged() const {}
        };
    }
}