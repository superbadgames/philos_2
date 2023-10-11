#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputController.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    enum class WindowType
    {
        OPEN_GL,
        VULKAN
    };

    class Window
    {
    public:
        Window(void);

        virtual ~Window(void);

        virtual bool v_Init(string gameName, U32 width, U32 height) = 0;

        virtual void v_Cleanup(void) = 0;

        virtual void v_ProcessEvents(void);

        void SetColor(glm::vec3& color);

        F64 GetMouseXDelta(void);

        F64 GetMouseYDelta(void);

        bool ShouldWindowClose(void);

        void CloseWindow(void);

        void RegisterInputController(p_InputController controller);

        void HideMouseCursor(void) const;

        void ShowMouseCursor(void) const;

        inline S32 GetScreenWidth(void) { return _bufferWidth; }

        inline S32 GetScreenHeight(void) { return _bufferHeight; }

    protected:
        GLFWwindow* _mainWindow;
        p_InputController _inputController;
        S32 _bufferWidth;
        S32 _bufferHeight;

        static void _KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void _MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);

        static void _MouseCursorHandler(GLFWwindow* window, double xPos, double yPos);

        void _CreateCallbacks(void);

        void _WindowCleanup(void);

    };
    typedef shared_ptr<Window> p_Window;
}