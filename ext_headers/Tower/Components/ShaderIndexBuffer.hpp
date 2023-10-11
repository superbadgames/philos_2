#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include <GL/glew.h>
#include <vector>

namespace Tower
{
    class ShaderIndexBuffer
    {
    public:
        ShaderIndexBuffer(void);

        ~ShaderIndexBuffer(void);

        // Q: Why this is non-const?
        // A: It is because of the VBO. This handle needs to be reset, cleared, without deleting the memory from
        // the video card. This component must be able to be copied because the ComponnetArray needs to be tightly
        // packed memory. Basically, this should be thought of as a unique pointer. Once you copy it, you invalidate
        // the one you're copying from, and it should probably be deleted soon.
        ShaderIndexBuffer& operator=(ShaderIndexBuffer& param);

        void Set(U32* input, U32 length);

        void Set(std::vector<U32>& input);

        inline GLuint GetHandle(void) const { return IBO; }

        void ResetHandle(void);

        inline U32 GetCount(void) const { return _count; }

        inline bool IsInUse(void) const { return _isInUse; }

        void Bind(void);

        void UnBind(void);

    private:
        ShaderIndexBuffer(const ShaderIndexBuffer& other);

        GLuint IBO;
        U32 _count;
        bool _isInUse;

    };
}