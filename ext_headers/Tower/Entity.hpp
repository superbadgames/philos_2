#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Object.hpp"

namespace Tower
{
    class Entity : public Object
    {
    public:
        Entity(void);

        virtual ~Entity(void);

        virtual void v_PerformActions(F32 delta) {};

    private:

    };
    typedef shared_ptr<Entity> p_Entity;
}