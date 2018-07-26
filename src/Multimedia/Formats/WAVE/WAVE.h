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
#pragma once
//Local
#include <Std++/Containers/FiniteSet/FiniteSet.hpp>
#include <Std++/Containers/Map/Map.hpp>
#include <Std++/Multimedia/CodecId.hpp>
//Namespaces
using namespace StdXX;
using namespace StdXX::Multimedia;
//Local
#include "../../FourCC.h"

//Definitions
#define WAVE_RIFFCHUNK_CHUNKID FOURCC("RIFF")
#define WAVE_RIFFCHUNK_RIFFTYPE FOURCC("WAVE")
#define WAVE_FORMATCHUNK_CHUNKID FOURCC("fmt ")
#define WAVE_DATACHUNK_CHUNKID FOURCC("data")

//Functions
void AddMS_TwoCC_AudioCodecs(FiniteSet<CodecId> &refCodecSet);
uint16 MapToTwoCC(CodecId codecId);