#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include "Simulator/Zipper.hpp"
#include "Simulator/Wall.hpp"
#include "Simulator/Mine.hpp"
#include <Tower/Components/EntityFactory.hpp>

namespace Philos
{

    class ObjectFactory : public Tower::EntityFactory
    {
    public:
        ObjectFactory(void);

        ~ObjectFactory(void) final;

        Tower::p_Entity v_Create(U32 typeId) final;

        enum GAME_OBJECT_TYPES
        {
            SIMULATOR_ZIPPER = 1,
            SIMULATOR_WALL = 2,
            SIMULATOR_MINE = 3,
        };
    };
}