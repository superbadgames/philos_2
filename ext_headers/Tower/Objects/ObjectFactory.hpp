#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Objects/Player.hpp"

namespace Tower
{
    class ObjectFactory
    {
    public:
        ObjectFactory(void) {};

        virtual ~ObjectFactory(void) {};

        p_Player virtual v_CreatePlayer(U32 typeId) = 0;

    };
}