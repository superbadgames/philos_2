#include "pch.h"
#include <Tower/framework.h>

#include "Simulator/SimulatorMap.hpp"
#include "Creator.hpp"

#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/ConfigurationManager.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Managers/ShaderManager.hpp>

int main(void)
{
    Tower::p_Director director = Tower::Director::Instance();

    // Window Type, Name, Width, Height, field of view, view distance
    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", 1200, 800, 45.0f, 5000.0f))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    // Should be deleted later. This code should live in the Player Objects where they are used
    //
    // Initialize Input Bindings
    //
    Tower::p_InputManager inputManager = Tower::InputManager::Instance();
    inputManager->AddBinding("exit", Tower::InputButton::ESCAPE);


    // Eventually, a more sophisticated method will be needed, maybe. See, there are going to be many shaders, and some
    // are going to be used only for some objects. Maybe, those objects, or their managers should control when the shaders
    // are loaded, or maybe a shader manager should do that, reading which shaders to load from a data base.
    // If, for instance, the data base has a config for shaders to load, then it could be changes and configured
    // from the editor later, for faster iterations on various shaders that will eventually be created. Just a thought.
    //
    // Initialize shaders
    //
    Tower::p_Shader basic3dShader = std::make_shared<Tower::Shader>();
    basic3dShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader("basic3d", basic3dShader);

    // Very much like the shaders, maybe a better way to add a deal with new textures is needed. If these were also entries
    // in a data base, it would give me more options.
    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture("zipper", "..\\..\\Assets\\Textures\\Simulator\\Zipper_texture.png");
    Tower::TextureManager::Instance()->LoadTexture("asteroid_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Asteroid_v1.png");
    Tower::TextureManager::Instance()->LoadTexture("mine_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Mine.png");
    Tower::TextureManager::Instance()->LoadTexture("wall_v1", "..\\..\\Assets\\Textures\\Simulator\\Simulator_Wall.png");

    // This should be moved. Here is a thought.
    // 1. The world calls the db, which has a list of models that need to be loaded.
    // 2. When a level is changed, or "unloaded", the models are deleted from memory, perhaps the
    //    model manager completely purges all loaded models?
    // 3. It reads the list of new models for the map to load. These models are loaded from memory,
    //    until the level is changed. when they are deleted. I could even add a hard change, or soft change
    //    to control when zones load and unload, so that you don't have to wait for the whole world to load
    //    because you go in a house, but if you go to a different zone, far away, loading screen will be doing
    //    all this work of unloading and loading models, textures and maybe even shaders.
    // 4. With the models loaded in memory, the assets will now be able to function when they are created next
    //    This is an important order of operations thing for the World code.
    //
    // Initialize 3D models
    //
    Tower::ModelManager::Instance()->Load("zipper", "..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("wall", "..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb", basic3dShader);
    Tower::ModelManager::Instance()->Load("mine", "..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb", basic3dShader);

    Philos::p_Creator createOfObjects = std::make_shared<Philos::Creator>();


    // Replace with global world, when database is working
    // Call me by my singleton name, once I know how to read a database
    Simulator::p_SimulatorMap simulatorMap = std::make_shared<Simulator::SimulatorMap>();
    // The factory must be set before the init is called. The init will create all the objects
    // and it can't do that without the factory.
    simulatorMap->SetFactory(createOfObjects);
    simulatorMap->v_Init();


    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        // This should be controlled by something else. Something like a World Update would make sense... but
        /// that isn't going to be a thing. I'm not sure. I need to think about this one.
        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }


        simulatorMap->Update(director->GetDeltaTime());
        simulatorMap->Render();

        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;
}
