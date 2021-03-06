/*
 * Copyright (c) 2019-2020 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/Compression/Compressor.hpp>
//Local
#include "gzip/gzipCompressor.hpp"
#ifdef _STDXX_EXTENSION_LIBLZMA
#include "../../src_backends/liblzma/LZMACompressor.hpp"
#endif
//Namespaces
using namespace StdXX;

//Public methods
void Compressor::Finalize()
{
}

//Class functions
Compressor *Compressor::Create(CompressionAlgorithm algorithm, OutputStream &outputStream, const Optional<uint8>& compressionLevel)
{
	return nullptr;
}

Compressor *Compressor::Create(CompressionStreamFormatType compressionStreamType, CompressionAlgorithm algorithm, OutputStream &outputStream, const Optional<uint8>& compressionLevel)
{
	switch(compressionStreamType)
	{
		case CompressionStreamFormatType::gzip:
			ASSERT(algorithm == CompressionAlgorithm::DEFLATE, u8"gzip only supports DEFLATE");
			return new _stdxx_::gzipCompressor(outputStream, compressionLevel);
#ifdef _STDXX_EXTENSION_LIBLZMA
		case CompressionStreamFormatType::lzma:
			return new _stdxx_::LZMACompressor(outputStream, compressionLevel);
#endif
	}
	return nullptr;
}
