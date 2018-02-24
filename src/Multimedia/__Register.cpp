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
//Audio codecs
#include "Codecs/MPEG/MP3/MP3_Codec.hpp"
#include "Codecs/PCM/S16LE/PCM_S16LE_Codec.hpp"

//Video codecs
#include "Codecs/BGR24/BGR24_Codec.hpp"
#include "Codecs/MPEG/MS_MPEG4_Part2_V2_Codec.hpp"
#include "Codecs/RGB24/RGB24_Codec.hpp"

//Formats
#include "Formats/BMP/BMP_Format.hpp"
#include "Formats/Matroska/MatroskaVideo.hpp"
#include "Formats/WAVE/WAVE_Format.hpp"

void MultimediaRegisterCodecsAndFormats()
{
	//Codecs
	//Audio codecs
	Codec::Register(new MP3_Codec);
	Codec::Register(new PCM_S16LE_Codec);

	//Video codecs
	Codec::Register(new BGR24_Codec);
	Codec::Register(new MS_MPEG4_Part2_V2_Codec);
	Codec::Register(new RGB24_Codec);

	//Formats
	Format::Register(new BMP_Format);
	Format::Register(new MatroskaVideo);
	Format::Register(new WAVE_Format);
}