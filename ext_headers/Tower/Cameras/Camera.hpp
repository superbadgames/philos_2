/*

A generalized interface for all the cameras in the engine.

I decided to use less instead of more. I'm only defining the bear minimum function that I need.

*/
#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera;
    typedef shared_ptr<Camera> p_Camera;

    class Camera
    {
    public:
        Camera(void);

        virtual ~Camera(void) {};

        // Should call either InitOrthographic or InitPerspective
        virtual void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) = 0;

        inline const glm::mat4& GetViewMatrix(void) const { return _viewMatrix; }

        inline const glm::mat4& GetProjectionMatrix(void) const { return _projectionMatrix; }

        inline const glm::vec3& GetPosition(void) const { return _position; }

        // Virtual so that other actions can take place here, if needed, such as recalculating a viewMatrix
        inline virtual void v_SetPosition(const glm::vec3& position) { _position = position; }

    protected:
        glm::mat4 _viewMatrix;
        glm::mat4 _projectionMatrix;
        glm::vec3 _position;

        void _InitOrthographic(F32 screenWidth, F32 screenHeight, F32 viewDistance);

        void _InitPerspective(F32 fieldOfView, F32 aspectRation, F32 viewDistance);
    };
}