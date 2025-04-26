#include "pch.h"
#include "Simulator/Zipper.hpp"

using namespace Simulator;

TheZipper::TheZipper(void) :
    _entity(nullptr),
    _rotation(),
    _forward(glm::vec3(0.0f, 0.0f, 1.0f)),
    _throttleLevel(0),
    _throttleMultiplier(150.0f),
    _activeControl(true)
{

}

TheZipper::~TheZipper(void)
{
}

void TheZipper::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = Tower::RenderEntityManager::Instance()->GetNext();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel(Tower::ModelManager::Instance()->Get("zipper"));
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture("zipper"));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    _entity->ToggleRendering(true);
}


void TheZipper::Update(F32 delta)
{
    //glm::vec2 mouseInput = Tower::InputManager::Instance()->GetMouseInputOffset();

    glm::vec3 newPosition = _entity->GetPosition();
    if (_activeControl)
    {
        if (Tower::InputManager::Instance()->IsBindingPressed("throttleUp") && _throttleLevel < _maxThrottle)
        {
            ++_throttleLevel;
        }
        if (Tower::InputManager::Instance()->IsBindingPressed("throttleDown") && _throttleLevel > -_maxThrottle)
        {
            --_throttleLevel;
        }
        if (Tower::InputManager::Instance()->IsBindingPressed("fullstop"))
        {
            _throttleLevel = 0;
        }
        if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
        {
            newPosition.x += _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
        {
            newPosition.x -= _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("up"))
        {
            newPosition.y += _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("down"))
        {
            newPosition.y -= _turnMultiplier * delta;
        }
    }

    SetPosition(newPosition + (_forward * ((_throttleMultiplier * _throttleLevel) * delta)));
}

void TheZipper::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}