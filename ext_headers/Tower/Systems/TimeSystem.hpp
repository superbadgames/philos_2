#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/System.hpp"
#include "Tower/Components/Clock.hpp"
#include <GL/glew.h> // This is required. If it doesn't get included before <GLFW/glfw3.h>, then there is a compiler error
#include <GLFW/glfw3.h>


namespace Tower
{
    class TimeSystem : public System
    {
    public:
        TimeSystem(void);

        ~TimeSystem(void);

        void Tick(void);

        void Tock(void);

        const Clock& GetDefaultClock(void) const;

    private:
        F64 _lastTime;
        F64 _currentTime;
        Clock _clock;
    };
}