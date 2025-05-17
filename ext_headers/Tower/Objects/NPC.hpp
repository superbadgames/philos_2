#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"

namespace Tower
{
    class Entity;
    typedef shared_ptr<Entity> p_Entity;

    class Entity
    {
    public:
        Entity(void);

        virtual ~Entity(void);

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

        virtual void v_Update(F32 delta) {};

        inline p_Entity GetChild(void) const { return _child; }

        inline void SetChild(p_Entity entity) { _child = entity; }

        

    protected:
        p_Entity _child;
        p_Renderer _renderer;
    };
}