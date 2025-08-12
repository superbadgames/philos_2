#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/UI/Font.hpp"
#include "Tower/UI/Glyph.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Color.hpp"
#include "Tower/Math/Transform.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <map>
#include <vector>

namespace Tower
{
    class UIText;
    typedef shared_ptr<UIText> p_UIText;

    class UIText
    {
    public:
        UIText(void);

        ~UIText(void);

        void Init(p_Font font, const string& message, const Color& color);

        void Draw(const glm::mat4& projectionMatrix);

        void SetMessage(const string& message);

        void SetMessage(const string& message, const glm::vec3& position);

        void SetPosition(const glm::vec2& pos);

        void SetScale(const glm::vec3& scale);

    private:
        p_Font _font;
        string _message;
        Color _color;
        Transform _transform;
        // Cache the glyph shader
        // make this configurable later
        p_Shader _glyphShader;
        // Cache the glyphs required
        std::map<char, p_Glyph> _glyphs;
        std::vector<glm::vec3> _glyphPositions;

        void _SetupGlyphs(void);

        void _GenerateGlyphPositions(void);
    };
}