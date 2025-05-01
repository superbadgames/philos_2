#include "pch.h"
#include "Simulator/Wall.hpp"

using namespace Simulator;

Wall::Wall(void) :
    _renderer(nullptr),
    _rotation(),
    _active(false)
{

}

Wall::~Wall(void)
{

}

void Wall::Init(const glm::vec3& position)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get("wall"));
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture("wall_v1"));
    _renderer->SetPosition(position);
    _renderer->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _renderer->ToggleRendering(true);
}

void Wall::Update(F32 delta)
{

}
