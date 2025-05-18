/*

These are objects in the environment that should not move during normal gameplay. I guess some code COULD move them, but
they wont update frame by frame. If anything is going to happen to them, it's going to be special to that thing.

This is rocks, trees, grass, walls, solid things that don't move when you touch them. Most of the accessors are there
for the editor to manipulate.

*/
#pragma once

#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"
#include "Tower/Math/Transform.hpp"

namespace Tower
{
    class StaticEnvironmentObject;
    typedef shared_ptr<StaticEnvironmentObject> p_StaticEnvironmentObject;

    class StaticEnvironmentObject
    {
    public:
        StaticEnvironmentObject(void);

        StaticEnvironmentObject(const StaticEnvironmentObject& copy);

        StaticEnvironmentObject& operator=(const StaticEnvironmentObject& copy);

        ~StaticEnvironmentObject(void);

        virtual void v_Init(p_Transform transform) = 0;

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

        const glm::vec3& GetPosition(void) const;

        void SetPosition(const glm::vec3& position);

        const glm::vec3& GetScale(void) const;

        void SetScale(const glm::vec3& scale);

        const AxisAngle& GetRotation(void) const;

        void SetRotation(const AxisAngle& rotation);

        void SetRotation(F32 angle, const glm::vec3& axis);

        inline bool IsRendering(void) const { return _renderer->IsRendering(); }

        inline void ToggleRendering(bool state) { _renderer->ToggleRendering(state); }

        inline p_Renderer GetRenderer(void) const { return _renderer; }

        inline p_Transform GetTransform(void) const { return _transform; }

    protected:
        p_Renderer _renderer;
        p_Transform _transform;
    };
}