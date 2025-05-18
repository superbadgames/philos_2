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
    _transform = transform;
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("wall"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("wall_v1"));
    _renderer->SetTransform(_transform);
    _renderer->ToggleRendering(true);
}

void Wall::v_Activate(void)
{
    ToggleRendering(true);
}

void Wall::v_Deactivate(void)
{
    ToggleRendering(false);
}
