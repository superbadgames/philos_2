#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/GameObject.hpp"

namespace Tower
{
    class GameObjectFactory_I
    {
    public:
        GameObjectFactory_I(void) {};

        virtual ~GameObjectFactory_I(void) {};

        p_GameObject virtual v_CreateGameObject(U32 typeId) = 0;

    };
}