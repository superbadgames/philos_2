#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "glm/vec4.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

namespace Tower
{
    class Model
    {
    public:
        Model(void);

        ~Model(void);

        void LoadFromFile(const string& filepath, p_Shader shader);

        void Draw(void);

        void EnableWireframeMode(void);

        void DisableWireframeMode(void);

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:
        std::vector<p_Mesh> _meshes;
        p_Texture _texture;

        // aiNode is part of Assimp
        void _ProcessNode(aiNode* node, const aiScene* scene, p_Shader shader);

        // aiMesh is also part of Assimp
        p_Mesh _ProcessMesh(aiMesh* mesh, const aiScene* scene, p_Shader shader);
    };
    typedef shared_ptr<Model> p_Model;
}