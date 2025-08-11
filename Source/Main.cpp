#include "pch.h"
#include <Tower/framework.h>

#include "Creator.hpp"

#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/DatabaseManager.hpp>
#include <Tower/Managers/ConfigurationManager.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Components/World.hpp>

#include <Tower/UI/Font.hpp>
#include <Tower/UI/UIText.hpp>

int main(void)
{
    Tower::p_Director director = Tower::Director::Instance();

    // Window Type, Name, Width, Height, field of view, view distance
    if (!director->Init(Tower::WindowType::OPEN_GL, "..\\..\\Assets\\philos.db"))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    Tower::p_ShaderManager shaderManager = Tower::ShaderManager::Instance();

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
    shaderManager->RegisterShader("basic3d", basic3dShader);

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

    Tower::World world{};
    world.Init(createOfObjects, "zipper", "editor");

    // Simulator bg color
    Tower::Director::Instance()->SetWindowBackgroundColor(glm::vec3(0.1f, 0.1f, 0.3f));
    world.LoadMap("simulator_map");

    //
    // Font testing area
    //
    // Filepath to a font
    // When one value is used, it's assumed to be nxn, hence, 64x64
    Tower::p_Font font = std::make_shared<Tower::Font>();
    font->Load("..\\..\\Assets\\Default\\Fonts\\arial.ttf", 64);

    Tower::Color helloWorldColor(0.0f, 0.3f, 1.0f);
    Tower::UIText helloWorldText {};
    helloWorldText.Init(font, "Hello WOrld", helloWorldColor);
    helloWorldText.SetPosition(glm::vec2(100.0f, 50.0f));




    while(!director->ShouldProgramClose())
    {
        director->StartFrame();

        // This should be controlled by something else. Something like a World Update would make sense... but
        /// that isn't going to be a thing. I'm not sure. I need to think about this one.
        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }


        world.Update(director->GetDeltaTime());
        world.Render();

        helloWorldText.Draw(world.GetPlayerOne()->GetCamera()->GetOrthographicMatrix());

        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;
}
