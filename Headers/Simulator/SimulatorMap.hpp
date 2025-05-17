#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "ObjectFactory.hpp"
#include "Simulator/Mine.hpp"
#include "Simulator/Wall.hpp"

#include <Tower/Components/World.hpp>
#include <Tower/Managers/TextureManager.hpp>

#include <Tower/Cameras/Camera3D.hpp>
#include <Tower/Cameras/FollowCamera.hpp>

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <random>

namespace Simulator
{
    // class SimulatorMap;
    // typedef shared_ptr<SimulatorMap> p_SimulatorMap;

    class SimulatorMap : public Tower::World
    {
    public:
        SimulatorMap(void);

        ~SimulatorMap(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

    private:
        // This is all basically data...
        // If this could come from data, would I even need this file?
        static const U32 NUM_WALLS = 500;
        Philos::ObjectFactory _factory;
        Wall _wallsLeft[NUM_WALLS];
        Wall _wallsRight[NUM_WALLS];
        static const U32 NUM_MINES = 500;
        Mine _mines[NUM_MINES];
        // Mover me up to the World
        Tower::p_Camera3D _editorCamera;
        Tower::p_FollowCamera _zipperCamera;
        Tower::p_Entity _theZipper;
        F32 _editorCameraMoveSpeed;
        F32 _editorCameraSprintMultiplier;
        bool _mouseOn;
        bool _builderInControl;
    };
    typedef shared_ptr<SimulatorMap> p_SimulatorMap;
}