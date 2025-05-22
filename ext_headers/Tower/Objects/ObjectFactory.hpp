#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Objects/Player.hpp"
#include "Tower/Objects/StaticEnvironment.hpp"
#include "Tower/Objects/DynamicEnvironment.hpp"

namespace Tower
{
    class ObjectFactory;
    typedef shared_ptr<ObjectFactory> p_ObjectFactory;

    class ObjectFactory
    {
    public:
        ObjectFactory(void) {};

        virtual ~ObjectFactory(void) {};

        p_Player virtual v_CreatePlayer(U32 typeId) = 0;

        p_StaticEnvironmentObject virtual v_CreateStaticEnvironment(U32 typeId, p_Transform transform) = 0;

        p_DynamicEnvironmentObject virtual v_CreateDynamicEnvironment(U32 typeId, p_Transform transform) = 0;

    };
}