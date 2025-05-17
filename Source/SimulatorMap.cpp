#include "pch.h"
#include "Simulator/SimulatorMap.hpp"

using namespace Simulator;

SimulatorMap::SimulatorMap(void) :
    _factory(),
    _wallsLeft(),
    _wallsRight(),
    _mines()
{

}


SimulatorMap::~SimulatorMap(void)
{

}


void SimulatorMap::v_Init(void)
{
    Tower::Director::Instance()->SetWindowBackgroundColor(glm::vec3(0.1f, 0.1f, 0.3f));

    _editor = _factory.v_CreatePlayer(1);
    _playerOne = _factory.v_CreatePlayer(2);

    F32 distance = 300.0f;
    glm::vec3 nextPositionLeft = glm::vec3(distance, 0.0f, distance);
    glm::vec3 nextPositionRight = glm::vec3(-distance, 0.0f, distance);

    Tower::AxisAngle wallRotation{};
    wallRotation.axis = glm::vec3(0.0f, 0.0f, 1.0f);
    wallRotation.angle = 90.0f;

    glm::vec3 wallScale(100.0f, 420.0f, 75.0f);

    for (U32 i = 0; i < NUM_WALLS; ++i)
    {
        _wallsLeft[i].Init(nextPositionLeft);
        _wallsLeft[i].SetRotation(wallRotation);
        _wallsLeft[i].SetScale(wallScale);
        _wallsLeft[i].Activate();

        _wallsRight[i].Init(nextPositionRight);
        _wallsRight[i].SetRotation(wallRotation);
        _wallsRight[i].SetScale(wallScale);
        _wallsRight[i].Activate();

        nextPositionLeft.z += distance;
        nextPositionRight.z += distance;
    }

    distance = 200.0f;
    nextPositionLeft = glm::vec3(10.0f, 50.0f, distance);

    for (U32 i = 0; i < NUM_MINES; ++i)
    {
        _mines[i].Init(nextPositionLeft);
        U32 randomSpeed = std::rand() % 100 + 15;
        _mines[i].SetMoveSpeed((F32)randomSpeed);

        U32 headOrTails = std::rand() % 2;

        if (headOrTails == 1)
        {
            _mines[i].SetMoveSide();
        }
        else
        {
            _mines[i].SetMoveUp();
        }

        _mines[i].Activate();
        nextPositionLeft.z += distance;
    }

    Tower::Director::Instance()->HideMouseCursor();
}

