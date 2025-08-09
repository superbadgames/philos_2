#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include <glm/vec2.hpp>

namespace Tower
{
    struct CharacterData
    {
        char character;
        p_Texture texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        F32 advance;

        CharacterData(void) :
        character(),
        texture(nullptr),
        size(),
        bearing(),
        advance()
        {}

        CharacterData(const CharacterData& copy) :
        character(copy.character),
        texture(copy.texture),
        size(copy.size),
        bearing(copy.bearing),
        advance(copy.advance)
        {}

        CharacterData& operator=(const CharacterData& copy)
        {
            if(this == &copy) return *this;

            character = copy.character;
            texture = copy.texture;
            size = copy.size;
            bearing = copy.bearing;
            advance = copy.advance;

            return *this;
        }

        CharacterData(char c, p_Texture inTexture, const glm::ivec2& inSize, const glm::ivec2& inBearing, F32 inAdvanced) :
        character(c),
        texture(inTexture),
        size(inSize),
        bearing(inBearing),
        advance(inAdvanced)
        {}
    };
}