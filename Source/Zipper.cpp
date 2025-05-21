#include "pch.h"
#include "Simulator/Zipper.hpp"

using namespace Simulator;

TheZipper::TheZipper(void) :
    _throttleLevel(0),
    _throttleMultiplier(150.0f),
    _activeControl(true)
{

}

TheZipper::TheZipper(const TheZipper& copy) :
    Player(copy),
    _throttleLevel(copy._throttleLevel),
    _throttleMultiplier(copy._throttleMultiplier),
    _activeControl(copy._activeControl)
{

}

TheZipper& TheZipper::operator=(const TheZipper& copy)
{
    if (this == &copy) return *this;

    Player::operator=(copy);

    _throttleLevel = copy._throttleLevel;
    _throttleMultiplier = copy._throttleMultiplier;
    _activeControl = copy._activeControl;

    return *this;
}

TheZipper::~TheZipper(void)
{
}

void TheZipper::v_Init(const glm::vec3& position)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("zipper"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("zipper"));
    _renderer->SetTransform(_transform);
    _renderer->ToggleRendering(true);

    _transform->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _transform->SetPosition(position);
    ToggleRendering(true);

    Tower::p_FollowCamera cam = std::make_shared<Tower::FollowCamera>();
    cam->v_Init();
    cam->SetOffset(glm::vec2(300.0f, 85.0f));
    cam->SetTarget(GetTransform());

    _camera = cam;

    // These should all come from the configuration db eventually
    Tower::InputManager::Instance()->AddWASDMovement("zipper_move_forward", "zipper_move_back", "zipper_move_right", "zipper_move_left");
    Tower::InputManager::Instance()->AddBinding("zipper_up", Tower::InputButton::E);
    Tower::InputManager::Instance()->AddBinding("zipper_down", Tower::InputButton::Q);
    Tower::InputManager::Instance()->AddBinding("zipper_throttleUp", Tower::InputButton::W);
    Tower::InputManager::Instance()->AddBinding("zipper_throttleDown", Tower::InputButton::S);
    Tower::InputManager::Instance()->AddBinding("zipper_fullstop", Tower::InputButton::SPACE);
}


void TheZipper::v_Activate(void)
{
    _active = true;
}


void TheZipper::v_Deactivate(void)
{
    _active = false;
}


void TheZipper::v_Update(F32 delta)
{
    //glm::vec2 mouseInput = Tower::InputManager::Instance()->GetMouseInputOffset();

    glm::vec3 newPosition = GetPosition();
    if (_active)
    {
        if (Tower::InputManager::Instance()->IsBindingPressed("zipper_throttleUp") && _throttleLevel < _maxThrottle)
        {
            ++_throttleLevel;
        }
        if (Tower::InputManager::Instance()->IsBindingPressed("zipper_throttleDown") && _throttleLevel > -_maxThrottle)
        {
            --_throttleLevel;
        }
        if (Tower::InputManager::Instance()->IsBindingPressed("zipper_fullstop"))
        {
            _throttleLevel = 0;
        }
        if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("zipper_move_left"))
        {
            newPosition.x += _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("zipper_move_right"))
        {
            newPosition.x -= _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("zipper_up"))
        {
            newPosition.y += _turnMultiplier * delta;
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("zipper_down"))
        {
            newPosition.y -= _turnMultiplier * delta;
        }
    }

    SetPosition(newPosition + (_transform->GetForward() * ((_throttleMultiplier * _throttleLevel) * delta)));

    _camera->v_Update(delta);
}
