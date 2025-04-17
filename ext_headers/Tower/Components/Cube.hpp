#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Color.hpp"

namespace Tower
{
    class Cube
    {
    public:
        Cube(void);

        ~Cube(void);

        void Init(p_Shader shader, p_Texture texture);

        void Draw(void);

    private:
        // Vertex Array Object
        U32 _vao;
        // Vertex Buffer Object
        U32 _vbo;
        // uv buffer object
        U32 _texcoordBuffer;
        // Element (or index) Buffer Object
        std::vector<F32> _vertices;
        std::vector<F32> _uvs;
        p_Texture _texture;
    };
    typedef shared_ptr<Cube> p_Cube;
}