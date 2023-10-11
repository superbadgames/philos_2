#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/gtx/quaternion.hpp"
#include <GL/glew.h>


namespace Tower
{
    template<typename T>
    class VertexAttribute
    {
    public:
        VertexAttribute(void);

        ~VertexAttribute(void);

        // Q: Why this is non-const?
        // A: It is because of the VBO. This handle needs to be reset, cleared, without deleting the memory from
        // the video card. This component must be able to be copied because the ComponnetArray needs to be tightly
        // packed memory. Basically, this should be thought of as a unique pointer. Once you copy it, you invalidate
        // the one you're copying from, and it should probably be deleted soon.
        VertexAttribute& operator=(VertexAttribute& param);

        void AttributePointer(U32 location);

        void SetData(T* inputArray, U32 length);

        void SetData(std::vector<T>& input);

        void SetDataAtLocation(T* inputArray, U32 length, U32 location);

        void SetDataAtLocation(std::vector<T>& input, U32 location);

        void BindTo(U32 location);

        void UnBindFrom(U32 location);

        inline U32 GetHandle(void) const { return VBO; }

        inline void ResetHandle(void) { VBO, _count = 0; }

        inline U32 GetCount(void) const { return _count; }

    protected:
        U32 VBO;
        U32 _count;

    private:
        VertexAttribute(const VertexAttribute& other);
    };
}