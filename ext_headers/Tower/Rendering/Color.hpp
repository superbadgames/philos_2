#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec4.hpp>

namespace Tower
{
    struct Color
    {
        F32 red;
        F32 green;
        F32 blue;

        Color(void);

        Color(const Color& copy);

        Color& operator=(const Color& copy);

        Color(F32 r, F32 g, F32 b);

        glm::vec4 ToVec4(void) const;
    };
}