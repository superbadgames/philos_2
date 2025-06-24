#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Objects/Player.hpp>
#include <Tower/Cameras/FollowCamera.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Systems/PhysicsSystem.hpp>
#include <Tower/Physics/Particle.hpp>
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
        F32 _maxThrottle;
        F32 _throttleLevel;
        F32 _throttleMultiplier;
        F32 _turnMultiplier;
        F32 _maxVelocity;
        bool _activeControl;
        Tower::p_Particle _physicsBody;
    };
}