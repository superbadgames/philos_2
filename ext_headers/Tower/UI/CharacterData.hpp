#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include <glm/vec2.hpp>

namespace Tower
{
    struct CharacterData
    {
        p_Texture texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        U32 advance;

        CharacterData(void) :
            texture(nullptr),
            size(),
            bearing(),
            advance()
        {}

        CharacterData(const CharacterData& character) :
            texture(character.texture),
            size(character.size),
            bearing(character.bearing),
            advance(character.advance)
        {}

        CharacterData(p_Texture inTexture, const glm::ivec2& inSize, const glm::ivec2& inBearing, U32 inAdvanced) :
            texture(inTexture),
            size(inSize),
            bearing(inBearing),
            advance(inAdvanced)
        {}
    };
}