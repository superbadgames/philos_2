#include "pch.h"
#include "Simulator/Mine.hpp"

using namespace Simulator;

Mine::Mine(void) :
    _moveUp(false),
    _moveSpeed(25.0f),
    _moveDirection(0.0f)
{

}

Mine::Mine(const Mine& copy) :
    DynamicEnvironmentObject(copy),
    _moveUp(copy._moveUp),
    _moveSpeed(copy._moveSpeed),
    _moveDirection(copy._moveDirection)
{

}

Mine& Mine::operator=(const Mine& copy)
{
    if (this == &copy) return *this;

    DynamicEnvironmentObject::operator=(copy);

    _moveDirection = copy._moveDirection;
    _moveSpeed = copy._moveSpeed;
    _moveUp = copy._moveUp;

    return *this;
}

Mine::~Mine(void)
{

}


void Mine::v_Activate(void)
{
    ToggleRendering(true);
    _active = true;
}

void Mine::v_Deactivate(void)
{
    ToggleRendering(false);
    _active = false;
}


void Mine::v_Init(Tower::p_Transform transform)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("mine"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("mine_v1"));
    _renderer->SetTransform(_transform);

    // Same as in the Wall class, this is kind of a bug. I wanted to copy the whole
    // transform, but the mines wont render if I do this.
    //_transform = transform;

    _transform->SetPosition(transform->GetPosition());
    _transform->SetScale(transform->GetScale());
    _transform->SetRotation(transform->GetRotation());

    ToggleRendering(true);
}

void Mine::v_Update(F32 delta)
{
    if (_active)
    {
        F32 angle = _transform->GetRotationAngle();
        if (angle <= -360.0f)
        {
            angle = 360.0f;
        }
        else if (angle >= 360.0f)
        {
            angle = -360.0f;
        }
        _transform->SetRotationAngle(angle - (10.0f * delta));

        glm::vec3 position = _transform->GetPosition();
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


        _transform->SetPosition(position);
    }
}
