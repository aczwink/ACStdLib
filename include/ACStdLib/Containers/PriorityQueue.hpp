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
//Local
#include "../Debug.h"
#include "Container.hpp"

namespace ACStdLib
{
    template<typename DataType>
    class PriorityQueue : public Container
    {
        struct Node
        {
            uint32 priority;
            DataType data;
            Node *next;
        };

    public:
        //Constructor
        PriorityQueue()
        {
            this->head = nullptr;
        }

        //Destructor
        ~PriorityQueue()
        {
            this->Release();
        }

        //Methods
        const DataType &GetFirst() const
        {
            return this->head->data;
        }

        uint32 GetFirstPriority() const
        {
            return this->head->priority;
        }

        void Insert(uint32 priority, const DataType &refValue)
        {
            Node *pNode, *pNode2;

            this->nElements++;

            if(!this->head)
            {
                this->head = (Node *)MemAlloc(sizeof(*this->head));
                this->head->priority = priority;
                this->head->data = refValue;
                this->head->next = NULL;

                return;
            }
            if(priority <= this->head->priority)
            {
                pNode = (Node *)MemAlloc(sizeof(*pNode));
                pNode->priority = priority;
                pNode->data = refValue;
                pNode->next = this->head;
                this->head = pNode;

                return;
            }

            pNode = this->head;
            while(pNode->next && pNode->next->priority < priority)
                pNode = pNode->next;

            pNode2 = (Node *)MemAlloc(sizeof(*pNode2));
            pNode2->priority = priority;
            pNode2->data = refValue;
            pNode2->next = pNode->next;
            pNode->next = pNode2;
        }

        DataType PopFirst()
        {
            Node *pNode;
            DataType tmp;

            ASSERT(this->nElements);

            tmp = this->head->data;
            pNode = this->head;
            this->head = this->head->next;
            this->nElements--;
            MemFree(pNode);

            return tmp;
        }

        void Release()
        {
            while(this->nElements)
                this->PopFirst();
        }

		void Remove(const DataType &value)
		{
			Node *node = this->head;

			if(this->head->data == value)
			{
				this->head = this->head->next;
				this->nElements--;
				delete node;
				return;
			}

			while(node->next)
			{
				if(node->next->data == value)
				{
					node->next = node->next->next;
					this->nElements--;
					delete node->next;
					return;
				}
				node = node->next;
			}
		}

	private:
		//Members
		Node *head;
    };
}