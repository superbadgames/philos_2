/*
    The Font acts sort of like a Glyph manager. Each Glyph is loaded
    from a tff file. These glyphs are created using FreeType, an open
    source font library. https://freetype.org/

    FreeType creates a vector based texture for each character requested.
    The Font will created the characters for the UTF-8 character set.

    Data about how to space the Texture, along with the texture itself
    are passed around via CharacterData. This is used by the Glyph, which
    holds the openGL handles.

    The Text will control the relative position, and spacing of each Glyph,
    and will either queue up, or will directly call the render calls for
    each Glyph.

*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/UI/CharacterData.hpp"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/UI/Glyph.hpp"
#include <glm/vec2.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

namespace Tower
{
    class Font;
    typedef shared_ptr<Font> p_Font;

    class Font
    {
    public:
        Font(void);

        Font(const Font& copy);

        Font& operator=(const Font& copy);

        ~Font(void);

        // A width of 0 will allow the width to dynamically scaled with the height
        void Load(const string& filepath, U32 height, U32 width = 0);

        p_Glyph GetGlyph(char character);

        inline void SetNumCharacters(U32 num) { _numCharacters = num; }

    private:
        U32 _numCharacters;
        std::map<char, p_Glyph> _glyphs;

        void _LoadCharacterData(const string& filepath, U32 height, U32 width);

        void _CreateGlyphs(void);
    };
}