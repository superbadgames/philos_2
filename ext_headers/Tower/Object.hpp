#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Transform.hpp"
//#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Model.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Rendering/Shader.hpp"

namespace Tower
{
    class Object
    {
    public:
        Object(void);

        ~Object(void);

        virtual void v_Draw(const glm::mat4& viewMatrix)
        {
            DefaultDraw(viewMatrix);
        }

        void DefaultDraw(const glm::mat4& viewMatrix);

        inline void AddTexture(p_Texture texture)
        {
            _model->SetTexture(texture);
        }

        inline glm::vec3 GetPosition(void) const
        {
            return _transform.GetPosition();
        }

        inline void SetPosition(const glm::vec3& position)
        {
            _transform.SetPosition(position);
        }

        inline const glm::vec3& GetScale(void) const
        {
            return _transform.GetScale();
        }

        inline void SetScale(const glm::vec3& scale)
        {
            _transform.SetScale(scale);
        }

        inline void SetTransform(const Transform& transform)
        {
            _transform = transform;
        }

        inline const Transform& GetTransform(void)
        {
            return _transform;
        }

        inline const glm::mat4 GetTransformMatrix(void)
        {
            return _transform.ToMatrix();
        }

        inline p_Model GetModel(void) const
        {
            return _model;
        }

        inline void SetModel(p_Model model)
        {
            _model = model;
        }

    private:
        Transform _transform;
        p_Model _model;
    };
    typedef shared_ptr<Object> p_Object;
}