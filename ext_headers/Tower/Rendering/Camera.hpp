#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/mat4x4.hpp>

namespace Tower
{
    class Camera
    {
    public:
        Camera(void);

        ~Camera(void);

        const glm::mat4& GetMatrix(void) const
        {
            return _viewMatrix;
        }

    private:
        glm::mat4 _viewMatrix;
        // ProjectionMatrix = glm::perspective(fov, aspect, nearDraw, farDraw);

    };
    typedef shared_ptr<Camera> p_Camera;
}