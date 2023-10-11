#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera
    {
    public:
        Camera(void);

        Camera(glm::vec3 position, glm::vec3 worldUp, real yaw, real pitch, real moveSpeed, real turnSpeed);

        ~Camera(void);

        void Init(F32 fov=45.0f, S32 width=800, S32 height=600, F32 near=0.1f, F32 far=100.0f);

        // TODO: Should delta time be part of this? Or should the camera just have its own clock? hmmm...
        void KeyControl(const bool* keys, F64 deltaTime);

        void MouseControl(F64 xChange, F64 yChange);

        glm::mat4 GetViewMatrix(void) const;

        inline glm::mat4 GetProjection(void) const { return _projection; }

    private:
        void _UpdateVectors(void);

        glm::mat4 _projection;
        glm::vec3 _position;
        glm::vec3 _front;
        glm::vec3 _up;
        glm::vec3 _right;
        glm::vec3 _worldUp;
        glm::vec3 _targetPosition;
        real _yaw;
        real _pitch;
        real _moveSpeed;
        real _turnSpeed;
    };
}