#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Objects/Player.hpp>
#include <Tower/Cameras/FPSCamera.hpp>

namespace TowerBuilder
{
    class Editor : public Tower::Player
    {
    public:
        Editor(void);

        Editor(const Editor& copy);

        Editor& operator=(const Editor& copy);

        ~Editor(void) final;

        void v_Init(const glm::vec3& position) final;

        void v_Activate(void) final;

        void v_Deactivate(void) final;

        void v_Update(F32 delta) final;
    private:
        F32 _moveSpeed;
        F32 _sprintSpeedModifier;
    };
    typedef shared_ptr<Editor> p_Editor;
}