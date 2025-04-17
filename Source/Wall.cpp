#include "pch.h"
#include "Simulator/Wall.hpp"

using namespace Simulator;

Wall::Wall(void) :
    _entity(nullptr),
    _rotation(),
    _active(false)
{

}

Wall::~Wall(void)
{

}

void Wall::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = Tower::EntityManager::Instance()->GetNext();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel(Tower::ModelManager::Instance()->Get("wall"));
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture("wall_v1"));
    _entity->SetPosition(position);
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->ToggleRendering(true);
}

void Wall::Update(F32 delta)
{

}
