#include "pch.h"
#include "Simulator/Mine.hpp"

using namespace Simulator;

Mine::Mine(void) :
    _entity(nullptr),
    _rotation(),
    _moveDirection(0.0f),
    _moveSpeed(25.0f),
    _active(false),
    _moveUp(false)
{

}

Mine::~Mine(void)
{

}

void Mine::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = Tower::EntityManager::Instance()->GetNext();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel(Tower::ModelManager::Instance()->Get("mine"));
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture("mine_v1"));
    _entity->SetPosition(position);
    _entity->SetScale(glm::vec3(5.0f, 5.0f, 5.0f));
    _entity->ToggleRendering(true);
    _rotation.axis = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Mine::Update(F32 delta)
{
    if (_active)
    {
        _rotation.angle -= delta * 10.0f;

        if (_rotation.angle <= -360.0f)
        {
            _rotation.angle = 360.0f;
        }
        else if (_rotation.angle >= 360.0f)
        {
            _rotation.angle = -360.0f;
        }

        glm::vec3 position = _entity->GetPosition();
        if (_moveUp)
        {
            if (position.y > _moveLimit)
            {
                _moveDirection.y = -1.0f;
            }
            else if (position.y < -_moveLimit)
            {
                _moveDirection.y = 1.0f;
            }
        }
        else
        {
            if (position.x > _moveLimit)
            {
                _moveDirection.x = -1.0f;
            }
            else if (position.x < -_moveLimit)
            {
                _moveDirection.x = 1.0f;
            }
        }

        position += _moveDirection * (_moveSpeed * delta);

        _entity->SetRotation(_rotation);
        _entity->SetPosition(position);


    }
}

void Mine::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}