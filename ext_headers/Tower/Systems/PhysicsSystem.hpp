/*

The Physics System is really just a collection of functions that needed a safe namespace to hide in.
It wont use any memory of it's one, but rather will contain all the general use functions required
for physics.

For instance, it has the Update function that every Particle needs to have called on it.

The Physics System is a singleton. There shouldn't be competing version of physics.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceRegistry.hpp"


namespace Tower
{
    class PhysicsSystem
    {
    public:
        ~PhysicsSystem(void);

        static shared_ptr<PhysicsSystem> Instance(void);

        void Update(F32 delta);

        inline const ForceRegistry& AccessForceRegistry(void) { return _forceRegistry; }

    private:
        static shared_ptr<PhysicsSystem> _instance;
        ForceRegistry _forceRegistry;

        PhysicsSystem(void);
    };
    typedef shared_ptr<PhysicsSystem> p_PhysicsSystem;
}