#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Texture.hpp"
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <GL/glew.h>
#include <array>

namespace Tower
{
    class Model
    {
    public:
        Model(void);

        ~Model(void);

        void Init(void);

        void Bind(bool state=true);

        string GetTextureName(void);

    private:
        GLuint VAO, VBO, IBO;
        string _textureName;

        void _CreateTriangle(void);

        void _CalcAverageNormals(U32* indices, U32 indiceCount, GLfloat* vertices, U32 verticeCount, U32 vertexLength, U32 normalOffset);
    };
    typedef shared_ptr<Model> p_Model;
}