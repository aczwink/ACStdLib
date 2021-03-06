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
#include <Std++/Rendering/VertexBuffer.hpp>
#include <Std++/Rendering/DeviceContext.hpp>
#include "OpenGLDeviceContext.hpp"
//Namespaces
using namespace _stdxx_;
using namespace StdXX;
using namespace StdXX::Rendering;

class OpenGLVertexBuffer : public VertexBuffer
{
public:
    //Constructor
    OpenGLVertexBuffer(AllocationPolicy policy, OpenGLDeviceContext &deviceContext);

    //Destructor
    ~OpenGLVertexBuffer();

    //Methods
    void Allocate(uint32 nVertices, uint32 vertexSize, const void *pData);
    void Write(uint32 offset, uint32 size, const void *data);

    //Inline
    inline void Bind() const
    {
        this->glFuncs.glBindBuffer(GL_ARRAY_BUFFER, this->id);
    }

private:
    //Members
	OpenGLDeviceContext &deviceContext;
	GLFunctions_2_0 &glFuncs;
    uint32 id;
    AllocationPolicy policy;
};