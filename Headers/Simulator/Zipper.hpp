#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Renderer.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <GLFW/glfw3.h>

namespace Simulator
{
    class TheZipper;
    typedef shared_ptr<TheZipper> p_TheZipper;

    class TheZipper
    {
    public:
        TheZipper(void);

        ~TheZipper(void);

        void Init(const glm::vec3& position);

        void Update(F32 delta);

        void SetPosition(const glm::vec3& pos);

        inline const glm::vec3& GetPosition(void) const { return _renderer->GetPosition(); }

        inline const glm::vec3& GetForward(void) const { return _forward; }

        inline void ActivateControls(void) { _activeControl = true; }

        inline void DeactivateControl(void) { _activeControl = false; }

    private:
        Tower::p_Renderer _renderer;
        Tower::AxisAngle _rotation;
        glm::vec3 _forward;
        const S32 _maxThrottle = 5;
        S32 _throttleLevel;
        F32 _throttleMultiplier;
        const F32 _turnMultiplier = 500.0f;
        bool _activeControl;
    };
}