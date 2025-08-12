#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/UI/CharacterData.hpp"
#include "Tower/Math/Transform.hpp"

namespace Tower
{
    class Glyph;
    typedef shared_ptr<Glyph> p_Glyph;

    class Glyph
    {
    public:
        Glyph(void);

        ~Glyph(void);

        void Load(const CharacterData &characterData, p_Shader shader);

        void Draw(void);

        void SetPosition(const glm::vec3& position);

        inline const glm::ivec2& GetBearing(void) const { return _characterData.bearing; }

        inline const glm::ivec2& GetSize(void) const { return _characterData.size; }

        inline U32 GetAdvance(void) const { return _characterData.advance; }

        inline void SetTransform(const Transform& transform) { _transform = transform; }

        inline const Transform& GetTransform(void) { return _transform; }



        private:
        // Vertex Array Object
        U32 _vao;
        // Vertex Buffer Object
        U32 _vbo;
        // uv buffer object
        U32 _texcoordBuffer;
        // Element (or index) Buffer Object
        U32 _ebo;
        std::vector<F32> _vertices;
        std::vector<F32> _uvs;
        std::vector<U32> _indices;
        CharacterData _characterData;
        // Only holds the scale, to change the shape of the
        // quad each glyph requires for drawing
        Transform _transform;

        // NO COPY!
        Glyph(const Glyph& copy);

        Glyph& operator=(const Glyph& copy);

        // DO NOT SET SCALE! This should come from the character data.
        void SetScale(const glm::vec3& scale);
    };
}