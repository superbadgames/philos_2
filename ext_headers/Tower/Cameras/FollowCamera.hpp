#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Cameras/Camera.hpp"
#include "Tower/Managers/InputManager.hpp"

namespace Tower
{
    class FollowCamera;
    typedef shared_ptr<FollowCamera> p_FollowCamera;

    class FollowCamera : public Camera
    {
    public:
        FollowCamera(void);

        ~FollowCamera(void) final;

        void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) final;

        void Update(const glm::vec3& targetPos, const glm::vec3& targetUp, const glm::vec3& targetDirection);

        inline void SetOffset(const glm::vec2& offset) { _cameraOffset = offset; }

        inline const glm::mat4& GetViewMatrix(void) const { return _viewMatrix; }

    private:
        glm::vec3 _eye;
        glm::vec3 _cameraForward;
        glm::vec3 _cameraLeft;
        glm::vec3 _cameraUp;
        glm::vec2 _cameraOffset;
        F32 _followDistance;
    };
}