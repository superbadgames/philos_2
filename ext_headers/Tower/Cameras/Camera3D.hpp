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
    class Camera3D;
    typedef shared_ptr<Camera3D> p_Camera3D;

    class Camera3D : public Camera
    {
    public:
        Camera3D(void);

        ~Camera3D(void) final;

        void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) final;

        void Update(F32 delta);

        void MoveForward(F32 speed);

        void MoveBack(F32 speed);

        void MoveRight(F32 speed);

        void MoveLeft(F32 speed);

        void MoveUp(F32 speed);

        void MoveDown(F32 speed);

    private:
        glm::vec3 _target;
        glm::vec3 _facingDirection;
        glm::vec3 _worldUp;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraRight;
        const F32 _radius = 10.0f;
        F32 _yaw;
        F32 _pitch;
        F32 _roll;
    };
}