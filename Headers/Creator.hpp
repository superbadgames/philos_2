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
    enum GAME_OBJECT_TYPES
    {
        EDITOR = 1,
        SIMULATOR_ZIPPER = 2,
        SIMULATOR_WALL = 3,
        SIMULATOR_MINE = 4,
        ALL_SIMULATOR_WALLS = 5,
    };

    class Creator;
    typedef shared_ptr<Creator> p_Creator;

    class Creator : public Tower::ObjectFactory
    {
    public:
        Creator(void);

        ~Creator(void) final;

        Tower::p_Player v_CreatePlayer(U32 typeId) final;

        Tower::p_StaticEnvironmentObject v_CreateStaticEnvironment(U32 typeId, Tower::p_Transform transform) final;

        Tower::p_DynamicEnvironmentObject v_CreateDynamicEnvironment(U32 typeId, Tower::p_Transform transform) final;


    private:
        static const U32 NUM_WALLS = 500;
    };
}