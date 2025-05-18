#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Objects/StaticEnvironment.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace Simulator
{
    class Wall;
    typedef shared_ptr<Wall> p_Wall;

    class Wall : public Tower::StaticEnvironmentObject
    {
    public:
        Wall(void);

        Wall(const Wall& copy);

        Wall& operator=(const Wall& copy);

        ~Wall(void);

        void v_Init(Tower::p_Transform transform);

        void v_Activate(void);

        void v_Deactivate(void);

    private:
    };
}