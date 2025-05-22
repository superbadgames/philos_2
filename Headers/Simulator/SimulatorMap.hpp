#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "Creator.hpp"
#include "Simulator/Mine.hpp"
#include "Simulator/Wall.hpp"

#include <Tower/Components/World.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Objects/Player.hpp>
#include <Tower/Builder/Editor.hpp>

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <random>

namespace Simulator
{
    class SimulatorMap;
    typedef shared_ptr<SimulatorMap> p_SimulatorMap;

    class SimulatorMap : public Tower::World
    {
    public:
        SimulatorMap(void);

        ~SimulatorMap(void) final;

        void v_Init(void) final;
    };
}