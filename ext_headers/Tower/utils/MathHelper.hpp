#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace Tower
{
    inline glm::vec3 lerp(const glm::vec3& s, const glm::vec3& e, F32 t)
    {
        return glm::vec3(
            s.x + (e.x - s.x) * t,
            s.y + (e.y - s.y) * t,
            s.z + (e.z - s.z) * t
        );
    }

    inline glm::vec3 slerp(const glm::vec3& s, const glm::vec3& e, F32 t)
    {
        if (t < 0.01f)
        {
            return lerp(s, e, t);
        }

        glm::vec3 from = glm::normalize(s);
        glm::vec3 to = glm::normalize(e);

        F32 theta = glm::angle(from, to);
        F32 sin_theta = real_sin(theta);

        F32 a = real_sin((1.0f - t) * theta) / sin_theta;
        F32 b = real_sin(t * theta) / sin_theta;

        return from * a + to * b;
    }

    inline glm::vec3 nlerp(const glm::vec3& s, const glm::vec3& e, F32 t)
    {
        glm::vec3 linear = lerp(s, e, t);
        return glm::normalize(linear);
    }

    inline glm::vec3 nlerp(const glm::quat& s, const glm::quat& e, F32 t)
    {
        glm::vec3 linear = glm::vec3(
            s.x + (e.x - s.x) * t,
            s.y + (e.y - s.y) * t,
            s.z + (e.z - s.z) * t
        );
        return glm::normalize(linear);
    }
}