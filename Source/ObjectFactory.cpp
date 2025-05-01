#include "pch.h"
#include "ObjectFactory.hpp"

using namespace Philos;

ObjectFactory::ObjectFactory(void)
{

}

ObjectFactory::~ObjectFactory(void)
{

}

Tower::p_Entity ObjectFactory::v_Create(U32 typeId)
{
    Tower::p_Entity entity;
    switch (typeId)
    {
    case SIMULATOR_ZIPPER:
        Simulator::TheZipper* zipper = new Simulator::TheZipper();
        zipper->Init(glm::vec3(0.0f));
        entity = std::make_shared<Tower::Entity>(zipper);
        return entity;
        // case SIMULATOR_WALL:
        //     // Make a wall
        //     break;
        // case SIMULATOR_MINE:
        //     // make a mine
        //     break;
        //     // test other cases
        // default:
        //     return nullptr;
    };
    return nullptr;
}

