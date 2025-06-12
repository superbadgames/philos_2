#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/Time.hpp"
#include "Tower/Rendering/Window.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Managers/DatabaseManager.hpp"
#include "Tower/Managers/RenderingManager.hpp"
#include "Tower/Managers/InputManager.hpp"
#include "Tower/Managers/TextureManager.hpp"
#include "Tower/Managers/ShaderManager.hpp"
#include "Tower/Managers/ModelManager.hpp"
#include "Tower/Systems/PhysicsSystem.hpp"
#include "Tower/Managers/ConfigurationManager.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    // Forward Declaration:
    // Needed to compile because the window uses the director in it's callback functions, so there are circular referenced, I think.
    class Window;
    typedef shared_ptr<Window> p_Window;

    enum class WindowType
    {
        OPEN_GL,
        VULKAN
    };

    class Director
    {
    public:
        ~Director(void);

        static shared_ptr<Director> Instance(void);

        // Ultimately, these arguments suck. This needs to be a db file, that the director will open, and read values from. Maybe this is where
        // I will start my db implementations, once, the world is sorted out
        bool Init(WindowType type, const string& db_filepath);

        void Cleanup(void);

        void StartFrame(void);

        void EndFrame(void);

        void ProcessEvents(void);

        bool ShouldProgramClose(void);

        void CloseProgram(void);

        void SetWindowBackgroundColor(const glm::vec3& color);

        void ShowMouseCursor(void);

        void HideMouseCursor(void);

        void ToggleMouse(void);

        F32 GetDeltaTime(void) const;

        F32 GetElapsedTime(void) const;

        S32 GetWindowWidth(void) const;

        S32 GetScreenHeight(void) const;

    private:
        static shared_ptr<Director> _instance;

        p_Window _window;
        Time _globalTime;

        Director(void);

    };
    typedef shared_ptr<Director> p_Director;
}