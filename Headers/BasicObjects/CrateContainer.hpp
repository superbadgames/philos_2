#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Object.hpp>

namespace Philos2
{
    class CrateContainer : public Tower::Object
    {
    public:
        CrateContainer(void);

        ~CrateContainer(void);

        void Init(void);

    private:
    };
}