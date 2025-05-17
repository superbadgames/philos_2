#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Cameras/Camera.hpp"
#include "Tower/Managers/InputManager.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class FPSCamera;
    typedef shared_ptr<FPSCamera> p_FPSCamera;

    class FPSCamera : public Camera
    {
    public:
        FPSCamera(void);

        ~FPSCamera(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

        void MoveForward(F32 speed);

        void MoveBack(F32 speed);

        void MoveRight(F32 speed);

        void MoveLeft(F32 speed);

        void MoveUp(F32 speed);

        void MoveDown(F32 speed);

    private:
        glm::vec3 _facingDirection;
        glm::vec3 _worldUp;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraRight;
        F32 _yaw;
        F32 _pitch;
        F32 _roll;
    };
}