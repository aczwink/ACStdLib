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
//Class header
#include <Std++/Cryptography/SecureRandomNumberGenerator.hpp>
//Global
#include <fcntl.h>
#include <unistd.h>
//Local
#include <Std++/Debug.hpp>
//Namespaces
using namespace StdXX::Crypto;

//Public methods
void SecureRandomNumberGenerator::NextBytes(void *destination, uint32 count)
{
	int fd = open(u8"/dev/urandom", O_RDONLY);
	ASSERT(fd != -1, u8"REPORT THIS PLEASE!");

	byte *dest = static_cast<byte *>(destination);
	while(count > 0)
	{
		ssize_t result = read(fd, dest, count);
		ASSERT(result != -1, u8"REPORT THIS PLEASE!");

		dest += result;
		count -= result;
	}

	close(fd);
}
