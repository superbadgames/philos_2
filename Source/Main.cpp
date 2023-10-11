#include "pch.h"
#include "framework.hpp"
#include <Tower/Managers/Director.hpp>

#include <GLFW/glfw3.h>


#include <iostream>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;
    const U32 BASIC_SHADER_ID = 1;
    const U32 CRATE_TEXTURE_ID = 1;

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
    director->GetTextureManager()->LoadTexture(CRATE_TEXTURE_ID, "..\\..\\Assets\\Textures\\container.jpg");

    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}