#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include "Simulator/Zipper.hpp"
#include "Simulator/Wall.hpp"
#include "Simulator/Mine.hpp"
#include <Tower/Objects/ObjectFactory.hpp>
#include <Tower/Builder/Editor.hpp>

namespace Philos
{

    class ObjectFactory : public Tower::ObjectFactory
    {
    public:
        ObjectFactory(void);

        ~ObjectFactory(void) final;

        Tower::p_Player v_CreatePlayer(U32 typeId) final;



        enum GAME_OBJECT_TYPES
        {
            EDITOR = 1,
            SIMULATOR_ZIPPER = 2,
            SIMULATOR_WALL = 3,
            SIMULATOR_MINE = 4,
        };
    };
}