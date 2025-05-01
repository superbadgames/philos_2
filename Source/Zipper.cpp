#include "pch.h"
#include "Simulator/Zipper.hpp"

using namespace Simulator;

TheZipper::TheZipper(void) :
    _renderer(nullptr),
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
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("zipper"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("zipper"));
    _renderer->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _renderer->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    _renderer->ToggleRendering(true);
}


void TheZipper::Update(F32 delta)
{
    //glm::vec2 mouseInput = Tower::InputManager::Instance()->GetMouseInputOffset();

    glm::vec3 newPosition = _renderer->GetPosition();
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
    _renderer->SetPosition(pos);
}