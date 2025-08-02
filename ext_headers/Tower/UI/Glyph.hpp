#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Sprite.hpp"
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

        void SetPosition(const glm::vec3 &pos);

        const glm::vec3 &GetPosition(void) const;

        inline void SetCharacterData(const CharacterData &data) { _characterData = data; }

        inline const CharacterData &GetCharacterData(void) const { return _characterData; }

    private:
        CharacterData _characterData;
    };
}