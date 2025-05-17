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

        Renderer(const Renderer& copy);

        Renderer& operator=(const Renderer& copy);

        ~Renderer(void);

        inline S32 GetId(void) const { return _id; }

        // Will reset the Renderer, indicates that a Map has just changed
        void Reset(void);

        // The Model Matrix holds the transformation needed for the object to be positioned in the world.
        void Render(const glm::mat4& viewMatrix) const;

        void AddModel(void);

        void AddModel(const string& filePath);

        inline void AddModel(p_Model model) { _model = model; }

        inline p_Model GetModel(void) const { return _model; }

        void AddSprite(p_Shader shader, p_Texture texture);

        inline p_Sprite GetSprite(void) const { return _sprite; }

        void AddCubeModel(p_Texture texture);

        inline p_Cube GetCubeModel(void) const { return _cubeModel; }

        void AddShader(void);

        inline void AddShader(p_Shader shader) { _shader = shader; }

        p_Shader GetShader(void) const;

        void AddTexture(const string& filepath);

        inline void AddTexture(p_Texture texture) { _model->SetTexture(texture); }

        void SetColor(const Color& color);

        inline const Color& GetColor(void) const { return _color; }

        inline bool IsRendering(void) const { return _isRendering; }

        inline void SetRendering(bool state) { _isRendering = state; }

        inline void ToggleRendering(void) { _isRendering = !_isRendering; }

        inline void ToggleRendering(bool state) { _isRendering = state; }

        inline void ToggleShouldReset(void) { _shouldReset = !_shouldReset; }

        inline bool ShouldReset(void) const { return _shouldReset; }

        inline void SetTransform(p_Transform transform) { _transform = transform; }

        inline p_Transform GetTransform(void) const { return _transform; }

    private:
        static S32 _NEXT_ID;
        bool _isRendering;
        bool _shouldReset;
        S32 _id;
        p_Model _model;
        p_Sprite _sprite;
        p_Cube _cubeModel;
        p_Shader _shader;
        p_Transform _transform;
        Color _color;
    };
}