#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/utils/MathHelper.hpp"
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Transform
    {
    public:
        Transform(void);

        Transform(const glm::vec3& pos, const glm::quat& rot, const glm::vec3& scale);

        ~Transform(void) {}

        Transform Combine(const Transform& first, const Transform& second);

        Transform Inverse(void);

        // Interpolate between two transforms. Implement later
        Transform Mix(const Transform& first, const Transform& second, F32 t);

        glm::mat4 ToMatrix(void);

        Transform FromMatrix(const glm::mat4& matrix);

        glm::vec3 TransformPoint(const glm::vec3& point);

        glm::vec3 TransformVector(const glm::vec3& vector);

        inline void SetPosition(const glm::vec3& pos)
        {
            _position = pos;
        }

        inline const glm::vec3& GetPosition(void) const
        {
            return _position;
        }

        inline void SetRotation(const glm::quat& rot)
        {
            _rotation = rot;
        }

        inline const glm::quat& GetRotation(void) const
        {
            return _rotation;
        }

        inline void SetScale(const glm::vec3& scale)
        {
            _scale = scale;
        }

        inline const glm::vec3& GetScale(void) const
        {
            return _scale;
        }

    private:
        glm::vec3 _position;
        glm::quat _rotation;
        glm::vec3 _scale;
    };
    typedef shared_ptr<Transform> p_Transform;
};