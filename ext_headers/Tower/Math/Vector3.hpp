#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "glm/vec3.hpp"

namespace Tower
{
    class Vector;
    typedef shared_ptr<Vector> p_Vector;

    class Vector
    {
    public:
        Vector(void);

        Vector(const Vector& copy);

        ~Vector(void);

        Vector& operator=(const Vector& copy);

        Vector operator+(const Vector& other) const;

        Vector operator+(F32 value) const;

        Vector& operator+=(const Vector& other);

        Vector& operator+=(F32 value);

        Vector operator-(const Vector& other) const;

        Vector operator-(F32 value) const;

        Vector& operator-=(const Vector& other);

        Vector& operator-=(F32 value);

        // The so called Dot, or Scalar operator
        F32 operator*(const Vector& other) const;

        F32 Dot(const Vector& other);

    private:
        glm::vec3 _vec;
    };
}