#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include "Tower/Physics/Particle.hpp"
#include "Tower/Physics/RigidBody/RigidBody2D.hpp"
#include "Tower/Physics/RigidBody/RigidBody3D.hpp"


#include <vector>

namespace Tower
{
    class ForceRegistry
    {
    public:
        ForceRegistry(void);

        ~ForceRegistry(void);

        void Add(p_Particle body, p_ForceGenerator forceGen);

        void Add(p_RigidBody2D body, p_ForceGenerator forceGen);

        void Add(p_RigidBody3D body, p_ForceGenerator forceGen);

        void Remove(p_Particle body, p_ForceGenerator forceGen);

        void Remove(p_RigidBody2D body, p_ForceGenerator forceGen);

        void Remove(p_RigidBody3D body, p_ForceGenerator forceGen);

        void Clear(void);

        void ApplyForces(void);

    private:
        struct _ParticleForceRegistration
        {
            p_Particle body;
            p_ForceGenerator forceGen;
        };

        struct _RigidBody2DForceRegistration
        {
            p_RigidBody2D body;
            p_ForceGenerator forceGen;
        };

        struct _RigidBody3DRegistration
        {
            p_RigidBody3D body;
            p_ForceGenerator forceGen;
        };


        std::vector<_ParticleForceRegistration> _particleRegistrations;
        std::vector<_RigidBody2DForceRegistration> _body2DRegistrations;
        std::vector<_RigidBody3DRegistration> _body3DRegistrations;

    };
    typedef shared_ptr<ForceRegistry> p_ForceRegistry;
}