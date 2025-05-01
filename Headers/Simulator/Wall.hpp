#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Renderer.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace Simulator
{
    class Wall;
    typedef shared_ptr<Wall> p_Wall;

    class Wall
    {
    public:
        Wall(void);

        ~Wall(void);

        void Init(const glm::vec3& position);

        void Update(F32 delta);

        inline void SetPosition(const glm::vec3& pos) { _renderer->SetPosition(pos); }

        inline void SetRotation(const Tower::AxisAngle& rotation) { _renderer->SetRotation(rotation); }

        inline void SetScale(const glm::vec3& scale) { _renderer->SetScale(scale); }

        inline void Activate(void) { _active = true; }

        inline void Deactivate(void) { _active = false; }

    private:
        Tower::p_Renderer _renderer;
        Tower::AxisAngle _rotation;
        bool _active;
    };
}