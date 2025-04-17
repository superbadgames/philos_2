#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Shader.hpp"
#include <unordered_map>

namespace Tower
{
    class ShaderManager
    {
    public:

        ~ShaderManager(void);

        static shared_ptr<ShaderManager> Instance(void);

        void LoadShader(const string& shaderID, const string& vertexFilepath, const string& fragmentFilepath);

        void RegisterShader(const string& shaderID, p_Shader shader);

        p_Shader GetShader(const string& shaderID);

    private:
        static shared_ptr<ShaderManager> _instance;
        std::unordered_map<string, p_Shader> _shaders;

        ShaderManager(void);
    };
    typedef shared_ptr<ShaderManager> p_ShaderManager;
}