#include "pch.h"
#include "Creator.hpp"

using namespace Philos;

Creator::Creator(void)
{

}

Creator::~Creator(void)
{

}

Tower::p_Player Creator::v_CreatePlayer(const string& typeName)
{
    Tower::p_Player returnObject = nullptr;

    if (strcmp(typeName.c_str(), "editor") == 0)
    {
        TowerBuilder::p_Editor editor = std::make_shared<TowerBuilder::Editor>();
        editor->v_Init(glm::vec3(0.0f, 30.0f, -50.0f));
        returnObject = editor;
    }
    else if (strcmp(typeName.c_str(), "zipper") == 0)
    {
        Simulator::p_TheZipper zipper = std::make_shared<Simulator::TheZipper>();
        zipper->v_Init(glm::vec3(0.0f));
        returnObject = zipper;
    }
    else
    {
        std::cerr << "Error! There is no such object with the type of " << typeName << std::endl
            << "Try checking your spelling. Look at how the object is added to the database, you may have to fix it there." << std::endl
            << "Keep trying! You got this!\n";
    }

    return returnObject;
}

Tower::p_StaticEnvironmentObject Creator::v_CreateStaticEnvironment(const string& typeName, Tower::p_Transform transform)
{
    Tower::p_StaticEnvironmentObject returnObject = nullptr;

    if (strcmp(typeName.c_str(), "simulator_wall") == 0)
    {
        Simulator::p_Wall wall = std::make_shared<Simulator::Wall>();
        wall->v_Init(transform);
        wall->v_Activate();
        returnObject = wall;
    }
    else
    {
        std::cerr << "Error! There is no such object with the type of " << typeName << std::endl
            << "Try checking your spelling. Look at how the object is added to the database, you may have to fix it there." << std::endl
            << "Keep trying! You got this!\n";
    }

    return returnObject;
}


Tower::p_DynamicEnvironmentObject Creator::v_CreateDynamicEnvironment(const string& typeName, Tower::p_Transform transform)
{
    Tower::p_DynamicEnvironmentObject returnObject = nullptr;

    if (strcmp(typeName.c_str(), "simulator_mine") == 0)
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
    else
    {
        std::cerr << "Error! There is no such object with the type of " << typeName << std::endl
            << "Try checking your spelling. Look at how the object is added to the database, you may have to fix it there." << std::endl
            << "Keep trying! You got this!\n";
    }

    return returnObject;
}