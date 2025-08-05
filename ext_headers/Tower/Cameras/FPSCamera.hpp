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

        FPSCamera(const FPSCamera& copy);

        FPSCamera& operator=(const FPSCamera& copy);

        ~FPSCamera(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

        void v_MoveForward(F32 speed) final;

        void v_MoveBack(F32 speed) final;

        void v_MoveRight(F32 speed) final;

        void v_MoveLeft(F32 speed) final;

        void v_MoveUp(F32 speed) final;

        void v_MoveDown(F32 speed) final;

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