#include "pch.h"
#include "Simulator/SimulatorMap.hpp"

using namespace Simulator;

SimulatorMap::SimulatorMap(void)
{

}


SimulatorMap::~SimulatorMap(void)
{

}


void SimulatorMap::v_Init(void)
{
    Tower::Director::Instance()->SetWindowBackgroundColor(glm::vec3(0.1f, 0.1f, 0.3f));

    _editor = _factory->v_CreatePlayer(Philos::GAME_OBJECT_TYPES::EDITOR);
    _playerOne = _factory->v_CreatePlayer(Philos::GAME_OBJECT_TYPES::SIMULATOR_ZIPPER);

    // This data needs to come from the db
    F32 distance = 300.0f;
    glm::vec3 nextPositionLeft = glm::vec3(distance, 0.0f, distance);
    glm::vec3 nextPositionRight = glm::vec3(-distance, 0.0f, distance);

    Tower::AxisAngle rotation{};
    rotation.axis = glm::vec3(0.0f, 0.0f, 1.0f);
    rotation.angle = 90.0f;

    Tower::p_Transform transform = std::make_shared<Tower::Transform>();
    transform->SetRotation(rotation);
    transform->SetScale(glm::vec3(100.0f, 420.0f, 75.0f));

    // Hard coded value here, this should be a client side db config entry
    for (U32 i = 0; i < 500; ++i)
    {
        // Left wall
        transform->SetPosition(nextPositionLeft);
        Tower::p_StaticEnvironmentObject leftWall = _factory->v_CreateStaticEnvironment(Philos::GAME_OBJECT_TYPES::SIMULATOR_WALL, transform);
        _staticEnvironment.push_back(leftWall);

        // Right wall
        transform->SetPosition(nextPositionRight);
        Tower::p_StaticEnvironmentObject rightWall = _factory->v_CreateStaticEnvironment(Philos::GAME_OBJECT_TYPES::SIMULATOR_WALL, transform);
        _staticEnvironment.push_back(rightWall);

        nextPositionLeft.z += distance;
        nextPositionRight.z += distance;
    }

    distance = 200.0f;
    nextPositionLeft = glm::vec3(10.0f, 50.0f, distance);

    // Mine
    rotation.axis = glm::vec3(0.0f, 1.0f, 0.0f);
    rotation.angle = 0.0f;

    transform->SetScale(glm::vec3(5.0f, 5.0f, 5.0f));
    transform->SetRotation(rotation);

    for (U32 i = 0; i < 250; ++i)
    {
        _dynamicEnvironment.push_back(_factory->v_CreateDynamicEnvironment(Philos::GAME_OBJECT_TYPES::SIMULATOR_MINE, transform));

        nextPositionLeft.z += distance;
        transform->SetPosition(nextPositionLeft);
    }

    _playerOne->v_Activate();
}
