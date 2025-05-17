#include "pch.h"
#include "ObjectFactory.hpp"

using namespace Philos;

ObjectFactory::ObjectFactory(void)
{

}

ObjectFactory::~ObjectFactory(void)
{

}

Tower::p_Player ObjectFactory::v_CreatePlayer(U32 typeId)
{
    Tower::p_Player returnObject = nullptr;

    if (typeId == EDITOR)
    {
        TowerBuilder::p_Editor editor = std::make_shared<TowerBuilder::Editor>();
        editor->v_Init(glm::vec3(0.0f, 0.0f, -25.0f));
        returnObject = editor;
    }
    else if (typeId == SIMULATOR_ZIPPER)
    {
        Simulator::p_TheZipper zipper = std::make_shared<Simulator::TheZipper>();
        zipper->v_Init(glm::vec3(0.0f));
        returnObject = zipper;
    }

    return returnObject;
}

