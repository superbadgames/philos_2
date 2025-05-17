#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Cameras/Camera.hpp"
#include <glm/vec2.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera2D;
    typedef shared_ptr<Camera2D> p_Camera2D;

    class Camera2D : public Camera
    {
    public:
        Camera2D(void);

        Camera2D(const Camera2D& copy);

        Camera& operator=(const Camera& copy);

        ~Camera2D(void) final;

        // Field of View is not used, but required by the base class
        void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) final;

        void Move(const glm::vec2& velocity);

        void CalculateViewMatrix(void);

        void SetPosition(const glm::vec2& position);

    private:

    };
}