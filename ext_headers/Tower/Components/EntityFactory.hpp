#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"

namespace Tower
{
    class EntityFactory
    {
    public:
        EntityFactory(void) {};

        virtual ~EntityFactory(void) {};

        p_Entity virtual v_Create(U32 typeId) = 0;

    };
}