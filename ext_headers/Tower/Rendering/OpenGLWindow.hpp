#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Window.hpp"
#include <glad/glad.h>
#include <glm/vec3.hpp>

#include <iostream>


namespace Tower
{
    class OpenGLWindow: public Window
    {
    public:
        OpenGLWindow(void);

        ~OpenGLWindow(void) final;

        bool v_Init(string gameName, U32 windowWidth, U32 windowHeight) final;

        void v_Cleanup(void) final;

        void v_ProcessEvents(void) final;

    private:

        static void _KeyInputHandler(GLFWwindow* window, int key, int code, int action, int mode);

        static void _MouseCursorHandler(GLFWwindow* window, double xPos, double yPos);

        static void _MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);
    };
    typedef shared_ptr<OpenGLWindow> p_OpenGLWindow;
}