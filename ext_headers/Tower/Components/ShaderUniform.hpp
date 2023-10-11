#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GL/glew.h>
#include <vector>

namespace Tower
{
    class ShaderUniform
    {
    public:
        static void Set(U32 slot, const U32& input);

        static void Set(U32 slot, const F32& input);

        static void Set(U32 slot, glm::vec2* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::vec2>& input);

        static void Set(U32 slot, glm::ivec2* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::ivec2>& input);

        static void Set(U32 slot, glm::vec3* input, U32 length);

        static void Set(U32 slot, std::vector<glm::vec3>& input);

        static void Set(U32 slot, glm::vec4* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::vec4>& input);

        static void Set(U32 slot, glm::ivec4* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::ivec4>& input);

        static void Set(U32 slot, glm::quat* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::quat>& input);

        static void Set(U32 slot, const glm::mat4* input, U32 length=1);

        static void Set(U32 slot, std::vector<glm::mat4>& input);
    private:
// This class will never be instantiated. Prevent it explicitly.
        ShaderUniform(void);

        ShaderUniform(const ShaderUniform&);

        ~ShaderUniform(void);

        ShaderUniform& operator=(const ShaderUniform&);
    };
}