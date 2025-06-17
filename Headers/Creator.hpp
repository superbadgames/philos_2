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
    class Creator;
    typedef shared_ptr<Creator> p_Creator;

    class Creator : public Tower::ObjectFactory
    {
    public:
        Creator(void);

        ~Creator(void) final;

        Tower::p_Player v_CreatePlayer(const string& typeName) final;

        Tower::p_StaticEnvironmentObject v_CreateStaticEnvironment(const string& typeName, Tower::p_Transform transform) final;

        Tower::p_DynamicEnvironmentObject v_CreateDynamicEnvironment(const string& typeName, Tower::p_Transform transform) final;


    private:
        static const U32 NUM_WALLS = 500;
    };
}