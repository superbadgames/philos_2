#include "pch.h"
#include "Runner.hpp"

#include "Simulator/SimulatorMap.hpp"

#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Managers/ShaderManager.hpp>

void LoadProject(F32 width, F32 height)
{
    Tower::p_InputManager inputManager = Tower::InputManager::Instance();

    //
    // Initialize Input Bindings
    //
    inputManager->AddArrowMovement("camera_move_up", "camera_move_down", "camera_move_right", "camera_move_left");
    inputManager->AddBinding("camera_sprint", Tower::InputButton::LEFT_SHIFT);

    inputManager->AddWASDMovement("move_forward", "move_back", "move_right", "move_left");
    inputManager->AddBinding("up", Tower::InputButton::E);
    inputManager->AddBinding("down", Tower::InputButton::Q);

    inputManager->AddBinding("toggleMouse", Tower::InputButton::ENTER);

    inputManager->AddBinding("swapControls", Tower::InputButton::TAB);
    inputManager->AddBinding("throttleUp", Tower::InputButton::W);
    inputManager->AddBinding("throttleDown", Tower::InputButton::S);
    inputManager->AddBinding("fullstop", Tower::InputButton::SPACE);

    //
    // Initialize shaders
    //
    Tower::p_Shader basic3dShader = std::make_shared<Tower::Shader>();
    basic3dShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader("basic3d", basic3dShader);

    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture("the_zipper", "..\\..\\Assets\\Textures\\Simulator\\Zipper_texture.png");
    Tower::TextureManager::Instance()->LoadTexture("asteroid_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Asteroid_v1.png");
    Tower::TextureManager::Instance()->LoadTexture("mine_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Mine.png");
    Tower::TextureManager::Instance()->LoadTexture("wall_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Wall.png");

    //
    // Initialize 3D models
    //
    Tower::ModelManager::Instance()->Load("zipper", "..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("wall", "..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("mine", "..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb", basic3dShader);

    F32 fov = 45.0f;
    F32 viewDistance = 5000.0f;
    Simulator::p_SimulatorMap simulatorMap = std::make_shared<Simulator::SimulatorMap>();
    simulatorMap->v_Init(width, height, fov, viewDistance);
}

void Update(F32 delta)
{
    simulatorMap->v_Update(delta);
}

void Render(void)
{
    simulatorMap->Render();
}