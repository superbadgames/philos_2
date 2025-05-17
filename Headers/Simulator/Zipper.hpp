#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Objects/Player.hpp>
#include <Tower/Cameras/FollowCamera.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <GLFW/glfw3.h>

namespace Simulator
{
    class TheZipper;
    typedef shared_ptr<TheZipper> p_TheZipper;

    class TheZipper : public Tower::Player
    {
    public:
        TheZipper(void);

        TheZipper(const TheZipper& copy);

        TheZipper& operator=(const TheZipper& copy);

        ~TheZipper(void);

        void v_Init(const glm::vec3& position) final;

        void v_Activate(void) final;

        void v_Deactivate(void) final;

        void v_Update(F32 delta) final;


    private:
        const S32 _maxThrottle = 5;
        S32 _throttleLevel;
        F32 _throttleMultiplier;
        const F32 _turnMultiplier = 500.0f;
        bool _activeControl;
    };
}