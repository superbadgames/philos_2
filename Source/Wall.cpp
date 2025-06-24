#include "pch.h"
#include "Simulator/Wall.hpp"

using namespace Simulator;

Wall::Wall(void)
{

}

Wall::Wall(const Wall& copy) :
    StaticEnvironmentObject(copy)
{

}

Wall& Wall::operator=(const Wall& copy)
{
    if (this == &copy) return *this;

    Wall::operator=(copy);

    return *this;
}

Wall::~Wall(void)
{

}

void Wall::v_Init(Tower::p_Transform transform)
{

    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingSystem::Instance()->GetNext();
    }


    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("wall"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("wall_v1"));
    _renderer->SetTransform(_transform);

    // This is a bug, that I don't know how to explain:
    //_transform = transform;
    //
    // Originally I wanted to copy the transform like this line, above. But, when I use
    // this copy method, it fails. I an not able to render any walls. When I copy the
    // values manually, it works. I have no idea why. I want to figure this out some day,
    // but not today.
    _transform->SetPosition(transform->GetPosition());
    _transform->SetScale(transform->GetScale());
    _transform->SetRotation(transform->GetRotation());

    ToggleRendering(true);

}

void Wall::v_Activate(void)
{
    //ToggleRendering(true);
}

void Wall::v_Deactivate(void)
{
    //ToggleRendering(false);
}
