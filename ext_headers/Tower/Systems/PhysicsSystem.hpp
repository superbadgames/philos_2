/*

The Physics System is really just a collection of functions that needed a safe namespace to hide in.
It wont use any memory of it's one, but rather will contain all the general use functions required
for physics.

For instance, it has the Update function that every Particle needs to have called on it.

The Physics System is a singleton. There shouldn't be competing version of physics.

TODO:

- Add a Release function that will release a physics body back to the pool.
  For instance, a ReleaseParticle(S32).

  This has a complication. The way that get next is tracked will have to change to account
  for the release. This can be solved with a S32 _FindNext(void) function.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/ConfigurationManager.hpp"
#include "Tower/Physics/Particle.hpp"
#include "Tower/Physics/Force/ForceRegistry.hpp"

#include <vector>

namespace Tower
{
    class PhysicsSystem;
    typedef shared_ptr<PhysicsSystem> p_PhysicsSystem;

    class PhysicsSystem
    {
    public:
        ~PhysicsSystem(void);

        static p_PhysicsSystem Instance(void);

        void IntegrateParticles(F32 delta);

        inline const ForceRegistry& AccessForceRegistry(void) { return _forceRegistry; }

        void ApplyForces();

        p_Particle GetNextParticle(void);

        p_Particle GetParticle(U32 id);

    private:
        static p_PhysicsSystem _instance;
        ForceRegistry _forceRegistry;
        // Treat as const, should only change in rare exceptions
        U32 MAX_ENTITIES;
        U32 _nextParticle;

        std::vector<p_Particle> _particles;

        PhysicsSystem(void);

        void _Init(void);
    };
}