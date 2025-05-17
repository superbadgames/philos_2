#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/AxisAngle.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Transform;
    typedef shared_ptr<Transform> p_Transform;

    class Transform
    {
    public:
        Transform(void);

        Transform(const Transform& copy);

        Transform& operator=(const Transform& copy);

        ~Transform(void);

        void Reset(void);

        glm::mat4 ToMatrix(void) const;

        inline const glm::vec3& GetPosition(void) const { return _position; }

        inline void SetPosition(const glm::vec3& position) { _position = position; }

        inline const glm::vec3& GetScale(void) const { return _scale; }

        inline void SetScale(const glm::vec3& scale) { _scale = scale; }

        inline const glm::vec3& GetForward(void) const { return _forward; }

        inline void SetForward(const glm::vec3& axis) { _forward = axis; }

        inline const AxisAngle& GetRotation(void) const { return _rotation; }

        inline void SetRotation(const AxisAngle& rotation) { _rotation = rotation; }

        void SetRotation(F32 angle, const glm::vec3& axis);

    private:
        glm::vec3 _position;
        glm::vec3 _scale;
        glm::vec3 _forward;
        AxisAngle _rotation;
    };
};