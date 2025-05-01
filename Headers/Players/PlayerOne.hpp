#pragma once

#include "pch.h"
#include <Tower/framework.h>

#include "Simulator/Zipper.hpp"

namespace Philos
{
    class PlayerOne
    {
    public:
        PlayerOne(void);

        ~PlayerOne(void);

    private:
        Simulator::p_TheZipper _zipper;

    };
}