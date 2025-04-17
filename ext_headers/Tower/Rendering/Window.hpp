#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Managers/InputManager.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    class Window
    {
    public:
        Window(void);

        ~Window(void);

        bool Init(string gameName, U32 width, U32 height);

        void Cleanup(void);

        void ProcessEvents(void);

        void SetColor(const glm::vec3& color);

        F64 GetMouseXDelta(void);

        F64 GetMouseYDelta(void);

        bool ShouldWindowClose(void);

        void CloseWindow(void);

        void HideMouseCursor(void) const;

        void ShowMouseCursor(void) const;

        inline S32 GetScreenWidth(void) { return _bufferWidth; }

        inline S32 GetScreenHeight(void) { return _bufferHeight; }

        // This is only meant to be called by the FrameBufferSizeHandler
        // Later, this could be updated to call a function to set the window size from code. That is not happening yet
        inline void UpdateScreenWidthAndHight(S32 width, S32 height)
        {
            _bufferWidth = width;
            _bufferHeight = height;
        }


    protected:
        GLFWwindow* _mainWindow;
        S32 _bufferWidth;
        S32 _bufferHeight;

        // I'm using the default atomic types here so that GLFW doesn't complain about my custom types
        static void _KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void _MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);

        static void _MouseCursorHandler(GLFWwindow* window, double xPos, double yPos);

        static void _FramebufferSizeHandler(GLFWwindow* window, int width, int height);

        void _CreateCallbacks(void);

        void _WindowCleanup(void);


    };
    typedef shared_ptr<Window> p_Window;
}