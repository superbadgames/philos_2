#include "pch.h"
#include <Tower/framework.h>

#include "Simulator/SimulatorMap.hpp"

#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Managers/ShaderManager.hpp>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;
    F32 width = (F32)WINDOW_WIDTH;
    F32 height = (F32)WINDOW_HEIGHT;
    F32 fov = 45.0f;
    F32 viewDistance = 5000.0f;

    Tower::p_Director director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    //
    // Initialize Input Bindings
    //
    Tower::p_InputManager inputManager = Tower::InputManager::Instance();
    inputManager->AddBinding("exit", Tower::InputButton::ESCAPE);
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
    Tower::TextureManager::Instance()->LoadTexture("zipper", "..\\..\\Assets\\Textures\\Simulator\\Zipper_texture.png");
    Tower::TextureManager::Instance()->LoadTexture("asteroid_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Asteroid_v1.png");
    Tower::TextureManager::Instance()->LoadTexture("mine_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Mine.png");
    Tower::TextureManager::Instance()->LoadTexture("wall_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Wall.png");

    //
    // Initialize 3D models
    //
    Tower::ModelManager::Instance()->Load("zipper", "..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("wall", "..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("mine", "..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb", basic3dShader);

    // Call me by my singleton name, once I know how to read a database
    Simulator::p_SimulatorMap simulatorMap = std::make_shared<Simulator::SimulatorMap>();
    simulatorMap->v_Init(width, height, fov, viewDistance);

    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }


        simulatorMap->v_Update(director->GetDeltaTime());
        simulatorMap->Render();

        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;
}
