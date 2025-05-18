#include "pch.h"
#include "Creator.hpp"

using namespace Philos;

Creator::Creator(void)
{

}

Creator::~Creator(void)
{

}

Tower::p_Player Creator::v_CreatePlayer(U32 typeId)
{
    Tower::p_Player returnObject = nullptr;

    if (typeId == GAME_OBJECT_TYPES::EDITOR)
    {
        TowerBuilder::p_Editor editor = std::make_shared<TowerBuilder::Editor>();
        editor->v_Init(glm::vec3(0.0f, 30.0f, -50.0f));
        returnObject = editor;
    }
    else if (typeId == GAME_OBJECT_TYPES::SIMULATOR_ZIPPER)
    {
        Simulator::p_TheZipper zipper = std::make_shared<Simulator::TheZipper>();
        zipper->v_Init(glm::vec3(0.0f));
        returnObject = zipper;
    }

    return returnObject;
}

Tower::p_StaticEnvironmentObject Creator::v_CreateStaticEnvironment(U32 typeId, Tower::p_Transform transform)
{
    Tower::p_StaticEnvironmentObject returnObject = nullptr;

    if (typeId == GAME_OBJECT_TYPES::SIMULATOR_WALL)
    {
        Simulator::p_Wall wall = std::make_shared<Simulator::Wall>();
        wall->v_Init(transform);
        wall->v_Activate();
        returnObject = wall;
    }

    return returnObject;
}


Tower::p_DynamicEnvironmentObject Creator::v_CreateDynamicEnvironment(U32 typeId, Tower::p_Transform transform)
{
    Tower::p_DynamicEnvironmentObject returnObject = nullptr;

    if (typeId == GAME_OBJECT_TYPES::SIMULATOR_MINE)
    {
        Simulator::p_Mine mine = std::make_shared<Simulator::Mine>();

        mine->v_Init(transform);
        U32 randomSpeed = std::rand() % 100 + 15;
        mine->SetMoveSpeed((F32)randomSpeed);

        U32 headOrTails = std::rand() % 2;

        if (headOrTails == 1)
        {
            mine->SetMoveSide();
        }
        else
        {
            mine->SetMoveUp();
        }

        mine->v_Activate();

        returnObject = mine;
    }

    return returnObject;
}