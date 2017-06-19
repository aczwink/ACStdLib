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
#include <ACStdLib/Multimedia/Codec.hpp>
//Local
#include "BGR24_Encoder.hpp"
//Namespaces
using namespace ACStdLib;
using namespace ACStdLib::Multimedia;

class BGR24_Codec : public Codec
{
public:
	//Methods
	Decoder *CreateDecoder(Stream &refStream) const
	{
		NOT_IMPLEMENTED_ERROR;
		//#include "CBGR24Decoder.h"
		//return new CBGR24Decoder(refStream);
		return nullptr;
	}

	Encoder *CreateEncoder() const
	{
		return new BGR24_Encoder;
	}

	AParser *CreateParser() const
	{
		return nullptr;
	}

	CodecId GetId() const
	{
		return CodecId::BGR24;
	}

	String GetName() const
	{
		return "24-bit B8G8R8 Interleaved (BGR24)";
	}
};