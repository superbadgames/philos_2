#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Clock.hpp"
#include "Tower/Rendering/Window.hpp"
#include "Tower/Rendering/Camera.hpp"
// OpenGLWindow must be included before ShaderManager!
#include "Tower/Rendering/OpenGLWindow.hpp"
#include "Tower/Managers/ShaderManager.hpp"
#include "Tower/Managers/TextureManager.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Input/InputController.hpp"
#include "Tower/Entity.hpp"

namespace Tower
{
    class Director
    {
    public:
        ~Director(void);

        static shared_ptr<Director> Instance(void);

        bool Init(WindowType type = WindowType::OPEN_GL, string name = "Tower Window", const U32 width = 800, const U32 height = 600, F32 fov = 90.0f);

        void Update(void);

        void Draw(void);

        void Cleanup(void);

        void ProcessEvents(void);

        bool ShouldProgramClose(void);

        void CloseProgram(void);

        void SetWindowBackgroundColor(glm::vec3& color);

        F32 GetDeltaTime(void) const;

        F32 GetElapsedTime(void) const;

        p_Window GetWindowPointer(void) const;

        p_ShaderManager GetShaderManager(void) const;

        p_TextureManager GetTextureManager(void) const;

        void RegisterInputWithWindow(p_InputController controller);


    private:
        static shared_ptr<Director> _instance;

        p_Window _window;
        Clock _time;
        // TODO: Make thse singleton
        p_ShaderManager _shaderManager;
        p_TextureManager _textureManager;
        p_Camera _camera;

        Director(void);

    };
    typedef shared_ptr<Director> p_Director;
}