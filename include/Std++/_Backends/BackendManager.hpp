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
//Local
#include "../Containers/PriorityQueue.hpp"
#include "../Containers/Map/Map.hpp"
#include "../__InitAndShutdown.h"
#include "Backend.hpp"
#include "ComputeBackend.hpp"

namespace StdPlusPlus
{
	class BackendManager
	{
		friend void ::ShutdownStdPlusPlus();
	public:
		//Inline
		inline Backend *GetActiveBackend(BackendType type)
		{
			if(!this->activeBackends.Contains(type))
				this->SetActiveBackend(this->GetPreferredBackend(type));

			return this->activeBackends[type];
		}

		inline ComputeBackend *GetActiveComputeBackend()
		{
			return static_cast<ComputeBackend *>(this->GetActiveBackend(BackendType::Compute));
		}

		inline void SetActiveBackend(Backend *backend)
		{
			if(this->activeBackends.Contains(backend->GetType()))
				this->activeBackends[backend->GetType()]->Unload();

			backend->Load();
			this->activeBackends[backend->GetType()] = backend;
		}

		//Inline functions
		static BackendManager &GetInstance()
		{
			static BackendManager instance;

			return instance;
		}

	private:
		//Members
		Map<BackendType, PriorityQueue<Backend *>> backends;
		Map<BackendType, Backend *> activeBackends;

		//Constructor
		inline BackendManager()
		{
			this->RegisterBackends();
		}

		//Methods
		void RegisterBackends();

		//Inline
		inline Backend *GetPreferredBackend(BackendType type) const
		{
			return this->backends[type].GetFirst();
		}

		inline void ReleaseAll()
		{
			for(auto &kv : this->backends)
				while(!kv.value.IsEmpty())
					delete kv.value.PopFirst();
			this->backends.Release();
			this->activeBackends.Release();
		}
	};
}