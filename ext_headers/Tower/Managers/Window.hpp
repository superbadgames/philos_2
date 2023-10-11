#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

namespace Tower
{
    class Window
    {
    public:
        Window(void);

        ~Window(void);

        bool Init(string const& title, U32 windowWidth, U32 windowHeight);

        void Update(void);

        void ProcessEvents(void);

        void Shutdown(void);

        bool ShouldWindowClose(void);

        void SetColor(glm::vec3 color);

        F64 GetMouseXDelta(void);

        F64 GetMouseYDelta(void);

        inline S32 GetBufferWidth(void) { return _bufferWidth; }

        inline S32 GetBufferHeight(void) { return _bufferHeight; }

        inline const bool* GetKeys(void) { return _keys; }

        inline const bool* GetMouseButtons(void) { return _mouseButtons; }

        static const U32 NUM_KEYS = 1024;
        static const U32 NUM_MOUSE_BUTTONS = 12;
    private:

        void _CreateCallbacks(void);

        static void _KeyInputHandler(GLFWwindow* window, int key, int code, int action, int mode);

        static void _MouseCursorHandler(GLFWwindow* window, double xPos, double yPos);

        static void _MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);

        GLFWwindow* _mainWindow;
        S32 _bufferWidth;
        S32 _bufferHeight;
        bool _keys[NUM_KEYS];
        bool _hasMouseMoved;
        bool _mouseButtons[NUM_MOUSE_BUTTONS];
        GLdouble _mouseXLastPos;
        GLdouble _mouseYLastPos;
        GLdouble _mouseXDelta;
        GLdouble _mouseYDelta;


    };
    typedef shared_ptr<Window> p_Window;
}