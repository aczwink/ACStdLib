/*
 * Copyright (c) 2017-2019,2021 Amir Czwink (amir130@hotmail.de)
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
#include <Std++/Multimedia/CodingFormat.hpp>
//Local
#include <Std++/Containers/BinaryTreeMap/BinaryTreeMap.hpp>
//Namespaces
using namespace StdXX;
using namespace StdXX::Multimedia;

//Global variables
BinaryTreeMap<CodingFormatId, CodingFormat *> g_codingFormats;

//Public methods
void CodingFormat::AddDecoder(Decoder *decoder, float32 quality)
{
	this->decoders.Insert({1 - quality, decoder});
}

void CodingFormat::AddEncoder(Encoder *encoder, float32 quality)
{
	this->encoders.Insert({1 - quality, encoder});
}

void CodingFormat::AddParser(Parser *parser, float32 quality)
{
	this->parsers.Insert({1 - quality, parser});
}

const Decoder *CodingFormat::GetBestMatchingDecoder() const
{
	if (this->decoders.IsEmpty())
		return nullptr;
	return this->decoders.Top().Get<1>();
}

const Encoder *CodingFormat::GetBestMatchingEncoder() const
{
	if (this->encoders.IsEmpty())
		return nullptr;
	return this->encoders.Top().Get<1>();
}

const Parser *CodingFormat::GetBestMatchingParser() const
{
	if (this->parsers.IsEmpty())
		return nullptr;
	return this->parsers.Top().Get<1>();
}

//Class functions
const CodingFormat *CodingFormat::GetCodingFormatById(CodingFormatId codingFormatId)
{
	if(g_codingFormats.Contains(codingFormatId))
		return g_codingFormats[codingFormatId];
	
	return nullptr;
}

void CodingFormat::Register(CodingFormat *codingFormat)
{
	g_codingFormats.Insert(codingFormat->GetId(), codingFormat);
}