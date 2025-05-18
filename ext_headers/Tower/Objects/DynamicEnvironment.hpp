/*

Not very different from the Static Environment Object, it will allow for an Update, which will in turn allow for the
object to be moved frame by frame, or the check for things to do frame by frame.

This type of object is good for things like items, obstacles, puzzle pieces, interact-able items.

*/
#pragma once

#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"
#include "Tower/Math/Transform.hpp"

namespace Tower
{
    class DynamicEnvironmentObject;
    typedef shared_ptr<DynamicEnvironmentObject> p_DynamicEnvironmentObject;

    class DynamicEnvironmentObject
    {
    public:
        DynamicEnvironmentObject(void);

        DynamicEnvironmentObject(const DynamicEnvironmentObject& copy);

        DynamicEnvironmentObject& operator=(const DynamicEnvironmentObject& copy);

        ~DynamicEnvironmentObject(void);

        virtual void v_Init(p_Transform transform) = 0;

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

        virtual void v_Update(F32 delta) = 0;

        inline bool IsActive(void) const { return _active; }

        inline void ToggleActive(bool state) { _active = state; }

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
        bool _active;
        p_Renderer _renderer;
        p_Transform _transform;
    };
}