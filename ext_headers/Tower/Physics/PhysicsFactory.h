#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/RigidBody/RigidBody2D.hpp"
#include "Tower/Physics/RigidBody/RigidBody3D.hpp"
#include "Tower/Physics/Force/GravityForce.hpp"

namespace Tower
{
    class PhysicsFactory
    {
    public:
        ~PhysicsFactory(void);

        inline p_RigidBody2D MakeRigidBody2D(void)
        {
            return p_RigidBody2D(new RigidBody2D());
        }

        inline p_RigidBody3D MakeRigidBody3D(void)
        {
            return p_RigidBody3D(new RigidBody3D());
        }

        inline p_GravityForce MakeGravityForce(void)
        {
            return p_GravityForce(new GravityForce());
        }

        static shared_ptr<PhysicsFactory> Instance(void);

    protected:
        PhysicsFactory(void);

    private:
        static shared_ptr<PhysicsFactory> _instance;
    };//end Class
    typedef shared_ptr<PhysicsFactory> p_PhysicsFactory;
}//end Namespace
