#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <GLFW/glfw3.h>


namespace Tower
{
    class Clock
    {
    public:
        Clock(void);

        ~Clock(void);

        void Tick(void);

        inline F32 GetDelta(void) const
        {
            return _delta;
        }

        inline F32 GetElapsed(void) const
        {
            return _elapsed;
        }

    private:
        F32 _last;
        F32 _current;
        F32 _delta;
        F32 _elapsed;
    };
    typedef shared_ptr<Clock> p_Clock;
}