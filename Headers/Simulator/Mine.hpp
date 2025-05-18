#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Objects/DynamicEnvironment.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace Simulator
{
    class Mine;
    typedef shared_ptr<Mine> p_Mine;

    class Mine : public Tower::DynamicEnvironmentObject
    {
    public:
        Mine(void);

        Mine(const Mine& copy);

        Mine& operator=(const Mine& copy);

        ~Mine(void);

        void v_Init(Tower::p_Transform transform);

        void v_Activate(void);

        void v_Deactivate(void);

        void v_Update(F32 delta);


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
        bool _moveUp;
        const F32 _moveLimit = 300.0f;
        F32 _moveSpeed;
        glm::vec3 _moveDirection;
    };
}