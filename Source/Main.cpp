#include "pch.h"
#include "framework.hpp"
#include <Tower/Managers/Director.hpp>


#include <Tower/Object.hpp>
#include <Tower/Rendering/Model.hpp>
#include <Tower/Components/World.hpp>


#include <GLFW/glfw3.h>


#include <iostream>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;
    const U32 BASIC_SHADER_ID = 1;
    const U32 CRATE_TEXTURE_ID = 1;
    const U32 BRICK_TEXTURE_ID = 2;
    const U32 DIRT_TEXTURE_ID = 3;

    Tower::p_Director director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    //
    // Initialize shaders
    //
    Tower::p_Shader basicShader = std::make_shared<Tower::Shader>();
    basicShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    director->GetShaderManager()->RegisterShader(BASIC_SHADER_ID, basicShader);

    //
    // Initialize Textures
    //
    director->GetTextureManager()->LoadTexture(CRATE_TEXTURE_ID, "..\\..\\Assets\\Default\\Textures\\container.jpg");
    director->GetTextureManager()->LoadTexture(BRICK_TEXTURE_ID, "..\\..\\Assets\\Default\\Textures\\brick.jpg");
    director->GetTextureManager()->LoadTexture(DIRT_TEXTURE_ID, "..\\..\\Assets\\Default\\Textures\\dirt.jpg");

    Tower::p_Model containerModel = std::make_shared<Tower::Model>();
    Tower::p_Model brickModel = std::make_shared<Tower::Model>();
    Tower::p_Model dirtModel = std::make_shared<Tower::Model>();

    containerModel->LoadFromFile("..\\..\\Assets\\Default\\Models\\cube.glb", basicShader);
    brickModel->LoadFromFile("..\\..\\Assets\\Default\\Models\\cube.glb", basicShader);
    dirtModel->LoadFromFile("..\\..\\Assets\\Default\\Models\\cube.glb", basicShader);

    containerModel->SetTexture(director->GetTextureManager()->GetTexture(CRATE_TEXTURE_ID));
    brickModel->SetTexture(director->GetTextureManager()->GetTexture(BRICK_TEXTURE_ID));
    dirtModel->SetTexture(director->GetTextureManager()->GetTexture(DIRT_TEXTURE_ID));

    std::vector<Tower::p_Object> objects;

    Tower::p_Object container = std::make_shared<Tower::Object>();
    Tower::p_Object brick = std::make_shared<Tower::Object>();
    Tower::p_Object dirt = std::make_shared<Tower::Object>();

    container->SetModel(containerModel);
    brick->SetModel(brickModel);
    dirt->SetModel(dirtModel);

    objects.push_back(container);
    //object.push_back(brick);
    //object.push_back(dirt);


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}