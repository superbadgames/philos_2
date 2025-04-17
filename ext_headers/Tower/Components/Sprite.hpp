#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Color.hpp"
#include "Tower/Rendering/Shader.hpp"
#include <vector>

namespace Tower
{
    class Sprite
    {
    public:
        Sprite(void);

        ~Sprite(void);

        void Init(p_Shader shader, p_Texture texture);

        void Draw(p_Shader shader, const Color& color);

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:

        // Vertex Array Object
        U32 _vao;
        // Vertex Buffer Object
        U32 _vbo;
        // uv buffer object
        U32 _texcoordBuffer;
        // Element (or index) Buffer Object
        U32 _ebo;
        std::vector<F32> _vertices;
        std::vector<F32> _uvs;
        std::vector<U32> _indices;
        p_Texture _texture;

    };
    typedef shared_ptr<Sprite> p_Sprite;
}