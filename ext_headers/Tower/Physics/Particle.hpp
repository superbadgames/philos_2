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
    class Particle;
    typedef shared_ptr<Particle> p_Particle;

    class Particle
    {
    public:
        Particle(void);

        Particle(const Particle& copy);

        Particle& operator=(const Particle& copy);

        Particle(p_Transform transform);

        ~Particle(void);

        inline void SetId(S32 id) { _id = id; }

        inline S32 GetId(void) const { return _id; }

        inline void SetTransform(p_Transform transform) { _transform = transform; }

        inline void SetInverseMass(F32 inverse) { _inverseMass = inverse; }

        inline void SetDamping(F32 damping) { _damping = damping; }

        inline void SetIsActive(void) { _active = true; }

        inline void SetNotActive(void) { _active = false; }

        inline bool IsActive(void) const { return _active; }

        inline void SetAcceleration(const glm::vec3 acceleration) { _acceleration = acceleration; }

        inline const glm::vec3& GetAcceleration(void) const { return _acceleration; }

        inline const glm::vec3& GetVelocity(void) const { return _velocity; }

        // Use with caution! This should really only be changed by the physics system
        inline void SetVelocity(const glm::vec3& velocity) { _velocity = velocity; }

        void SetMass(F32 mass);

        void Integrate(F32 delta);

        void AddForce(const glm::vec3& force);

    private:
        bool _active;
        S32 _id;
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
}