/*

A Particle is the simplest object that can be simulated in the physics engine.

*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    class Particle
    {
    public:
        Particle(void);

        Particle(p_Transform transform);

        ~Particle(void);

        inline void SetTransform(p_Transform transform) { _transform = transform; }

        void SetMass(F32 mass);

        inline void SetInverseMass(F32 inverse) { _inverseMass = inverse; }

        inline void SetDamping(F32 damping) { _damping = damping; }

        void Integrate(F32 delta);

        void AddForce(const glm::vec3& force);

    private:
        // This is a pointer to a Player or NPC's location and rotation info.
        // The physics system is allowed to change this because they are really
        // part of the some entity, at the end of the day.
        p_Transform _transform;
        glm::vec3 _velocity;
        glm::vec3 _acceleration;
        // 0.0 = 100% drag, no velocity after integration
        // 1.0f = no drag. Maybe 0.999 is better for the math
        F32 _damping;
        // Inverse to simplify math in the integrator.
        // An inverse mass of 0.0 implies an infinite mass,
        // thus acceleration will have no effect on the initial velocity
        F32 _inverseMass;
        // A representation of all the accumulated forces that are acting
        // on the object for this frame. Cleared each frame
        glm::vec3 _forces;

        void _ClearForces(void);
    };
    typedef shared_ptr<Particle> p_Particle;
}