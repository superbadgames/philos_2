#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace Simulator
{
    class Mine
    {
    public:
        Mine(void);

        ~Mine(void);

        void Init(const glm::vec3& position);

        void Update(F32 delta);

        void SetPosition(const glm::vec3& pos);

        inline void Activate(void) { _active = true; }

        inline void Deactivate(void) { _active = false; }

        inline void SetMoveUp(void)
        {
            _moveUp = true;
            _moveDirection.x = 0.0f;
            _moveDirection.y = 1.0f;
            _moveDirection.z = 0.0f;
        }

        inline void SetMoveSide(void)
        {
            _moveUp = false;
            _moveDirection.x = 1.0f;
            _moveDirection.y = 0.0f;
            _moveDirection.z = 0.0f;
        }

        inline void SetMoveSpeed(F32 speed) { _moveSpeed = speed; }

    private:
        Tower::p_Entity _entity;
        Tower::AxisAngle _rotation;
        glm::vec3 _moveDirection;
        F32 _moveSpeed;
        const F32 _moveLimit = 300.0f;
        bool _active;
        bool _moveUp;
    };
}