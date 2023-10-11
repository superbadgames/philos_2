#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Transform.hpp"
#include "Tower/Components/Model.hpp"
#include "Tower/Components/Shader.hpp"

namespace Tower
{
    class TowerObject
    {
    public:
        TowerObject(void);

        ~TowerObject(void);

        void AddTransform(void);

        void AddModel(void);

        void AddShader(void);

        glm::vec3 GetPosition(void) const;

        void SetPostion(glm::vec3 position);

        glm::vec3 GetRotation(void) const;

        void SetRotation(glm::vec3 rotation);

        glm::vec3 GetScale(void) const;

        void SetScale(glm::vec3 scale);

        glm::mat4 GetTransform(void) const;

        void BindModel(void);

        void InitModel(void);

        void CompileShader(string vertexFilepath, string fragmentFilepath);


    private:
        p_Transform _transform;
        p_Model _model;
        p_Shader _shader;

    };
}