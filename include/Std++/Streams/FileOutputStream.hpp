/*
 * Copyright (c) 2017-2020 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/FileSystem/Permissions.hpp>
#include "../FileSystem/Path.hpp"
#include "SeekableOutputStream.hpp"

namespace StdXX
{
    class STDPLUSPLUS_API FileOutputStream : public SeekableOutputStream
    {
    public:
        //Constructor
		/**
		 * If file does not exist, it is created.
		 * If it exists and overwrite is true, it is truncated.
		 * If it exists and overwrite is false, an error occurs.
		 *
		 * If a file could not be created because its parent path does not exist, a FileNotFoundException with the
		 * parent path is thrown.
		 *
		 * @param path
		 * @param overwrite
		 * @param permissions - pass null for default permissions
		 */
        FileOutputStream(const FileSystem::Path &path, bool overwrite = false, const FileSystem::Permissions* permissions = nullptr);
        //FileOutputStream
        ~FileOutputStream();
        //Methods
		void Flush() override;
        uint64 QueryCurrentOffset() const override;
        void SeekTo(uint64 offset) override;
        uint32 WriteBytes(const void *pSource, uint32 size) override;

		//Inline
		inline const FileSystem::Path &GetPath() const
		{
			return this->filePath;
		}

	private:
        //Members
        union
        {
            void *pFileHandle;
            int fileHandle;
        };
		FileSystem::Path filePath;
    };
}