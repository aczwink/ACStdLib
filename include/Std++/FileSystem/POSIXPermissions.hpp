/*
 * Copyright (c) 2020-2021 Amir Czwink (amir130@hotmail.de)
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
#include "Permissions.hpp"

namespace StdXX::FileSystem
{
	class POSIXPermissions : public Permissions
	{
		struct POSIXPermission
		{
			/**
			 * Read file/link or list children names of directory.
			 */
			bool read;
			/**
			 * Write file/link or manage contents of directory (i.e. delete children, create new children etc.)
			 */
			bool write;
			/**
			 * Execute file/link or read metadata from children if name is known.
			 */
			bool execute;
		};

	public:
		//Members
		int32 userId;
		int32 groupId;
		bool setUserIdOnExecution;
		bool setGroupIdOnExecution;
		bool sticky;
		POSIXPermission owner;
		POSIXPermission group;
		POSIXPermission others;

		//Constructor
		POSIXPermissions(int32 userId, int32 groupId, uint32 encodedMode);

		//Methods
		Permissions *Clone() const override;
		uint32 EncodeMode() const;
	};
}