#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    class GameObject_I;
    typedef shared_ptr<GameObject_I> p_GameObject;

    class GameObject_I
    {
    public:
        GameObject_I(void) {};

        virtual ~GameObject_I(void) {};

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

    private:
    };
}