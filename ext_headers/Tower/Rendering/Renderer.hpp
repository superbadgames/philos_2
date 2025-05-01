#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/Transform.hpp"
#include "Tower/Math/AxisAngle.hpp"
#include "Tower/Rendering/Model.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Components/Sprite.hpp"
#include "Tower/Components/Cube.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Color.hpp"

namespace Tower
{
    class Renderer;
    typedef shared_ptr<Renderer> p_Renderer;

    class Renderer
    {
    public:
        Renderer(void);

        ~Renderer(void);

        // Will reset the Renderer, indicates that a Map has just changed
        void Reset(void);

        void Render(const glm::mat4& viewMatrix) const;

        void AddModel(void);

        void AddModel(const string& filePath);

        inline void AddModel(p_Model model) { _model = model; }

        void AddSprite(p_Shader shader, p_Texture texture);

        void AddCubeModel(p_Texture texture);

        void AddShader(void);

        inline void AddShader(p_Shader shader) { _shader = shader; }

        p_Shader GetShader(void) const;

        void AddTexture(const string& filepath);

        inline void AddTexture(p_Texture texture) { _model->SetTexture(texture); }

        inline const Color& GetColor(void) const { return _color; }

        void SetColor(const Color& color);

        const glm::vec3& GetPosition(void) const;

        void SetPosition(const glm::vec3& position);

        const glm::vec3& GetScale(void) const;

        void SetScale(const glm::vec3& scale);

        const AxisAngle& GetRotation(void) const;

        void SetRotation(const AxisAngle& rotation);

        void SetRotation(F32 angle, const glm::vec3& axis);

        inline bool IsRendering(void) const { return _isRendering; }

        inline void SetRendering(bool state) { _isRendering = state; }

        inline void ToggleRendering(void) { _isRendering = !_isRendering; }

        inline void ToggleRendering(bool state) { _isRendering = state; }

        inline void ToggleShouldReset(void) { _shouldReset = !_shouldReset; }

    private:
        static S32 _NEXT_ID;
        bool _isRendering;
        bool _shouldReset;
        S32 _id;
        p_Model _model;
        p_Sprite _sprite;
        p_Cube _cubeModel;
        p_Shader _shader;
        Transform _transform;
        Color _color;
    };
}