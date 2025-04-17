#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/RigidBody/RigidBody2D.hpp"
#include "Tower/Physics/RigidBody/RigidBody3D.hpp"
#include "Tower/Physics/Particle.hpp"

namespace Tower
{
    class ForceGenerator
    {
    public:
        ForceGenerator(void);

        virtual ~ForceGenerator(void);

        virtual void v_UpdateForce(p_RigidBody2D body) = 0;

        virtual void v_UpdateForce(p_RigidBody3D body) = 0;

        virtual void v_UpdateForce(p_Particle body) = 0;

    };
    typedef shared_ptr<ForceGenerator> p_ForceGenerator;
}
