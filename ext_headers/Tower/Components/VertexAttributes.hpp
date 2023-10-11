#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include <GL/glew.h>
#include <vector>

namespace Tower
{
    class VertexAttributes
    {
    public:
        VertexAttributes(void);

        VertexAttributes(const VertexAttributes& other);

        ~VertexAttributes(void);

        void SetVertexPositions(std::vector<F32> positions, GLenum drawType);

        void SetVertexUVs(std::vector<F32> uvs, GLenum drawType);

        void SetVertexNormals(std::vector<F32> normals, GLenum drawType);

        void DeleteBuffers(void);


    private:
        static const U32 TOTAL_BUFFERS = 4;

        const U32 POSITION_BUFFER = 0;
        const U32 UV_BUFFER = 1;
        const U32 NORMAL_BUFFER = 2;
        const U32 INDEX_BUFFER = 3;

        const U32 POSITION_SLOT = 0;
        const U32 UV_SLOT = 1;
        const U32 NORMAL_SLOT = 2;

        GLuint _buffers[TOTAL_BUFFERS];
    };
}