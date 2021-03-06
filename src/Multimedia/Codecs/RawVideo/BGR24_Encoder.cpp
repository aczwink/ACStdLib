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
//Class header
#include "BGR24_Encoder.hpp"
//Local
#include <Std++/Multimedia/Packet.hpp>
#include <Std++/Multimedia/VideoFrame.hpp>

//Public methods
void BGR24_Encoder::Encode(const Frame &refFrame)
{
	NOT_IMPLEMENTED_ERROR; //TODO: reimplement but without stupid resampling and with new api
	/*
	byte *pBGR;
	RGBPixmap *pRGBImage;

	VideoFrame &refVideoFrame = (VideoFrame &)refFrame;

	//get image
	if(refVideoFrame.GetImage()->GetColorSpace() == ColorSpace::RGB)
	{
		pRGBImage = (RGBPixmap *)refVideoFrame.GetImage();
	}
	else
	{
		pRGBImage = (RGBPixmap *)refVideoFrame.GetImage()->Resample(ColorSpace::RGB);
	}

	//encode
	Packet *packet = new Packet;
	packet->Allocate(3 * pRGBImage->GetNumberOfPixels());

	pBGR = packet->GetData();
	for(uint16 y = 0; y < pRGBImage->GetHeight(); y++)
	{
		for(uint16 x = 0; x < pRGBImage->GetWidth(); x++)
		{
			auto color = pRGBImage->GetPixel(Math::Point<uint16>(y, x));

			*pBGR++ = color[2];
			*pBGR++ = color[1];
			*pBGR++ = color[0];
		}
	}
	this->AddPacket(packet);

	//clean up
	if(refVideoFrame.GetImage() != pRGBImage)
	{
		delete pRGBImage; //the frame that we converted
	}*/
}

void BGR24_Encoder::Flush()
{
	//this encoder always writes through
}
