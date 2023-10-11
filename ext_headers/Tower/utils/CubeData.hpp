#pragma once

#include "pch.h"
#include "Tower/framework.h"

#include <array>

namespace Tower
{
    struct CubeData
    {
        std::array<F32, 12> indices{
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 1, 2
        };

        std::array<F32, 12> vertices{
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
        };

        std::array<F32, 8> uvs{
        0.0f, 0.0f,
        0.5f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
        };

        std::array<F32, 12> normals{
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f
        };

    };
}
