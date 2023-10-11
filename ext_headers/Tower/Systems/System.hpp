#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <set>

namespace Tower
{
    class System
    {
    public:
        System(void);

        virtual ~System(void);

        std::set<Entity> Entities;
    };
    typedef shared_ptr<System> p_System;
}