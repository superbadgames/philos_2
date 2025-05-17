#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    class ConfigurationManager;
    typedef shared_ptr<ConfigurationManager> p_ConfigurationManager;

    class ConfigurationManager
    {
    public:
        U32 windowWidth;
        U32 windowHeight;
        S32 maxRenderers;
        F32 fov;
        F32 viewDistance;

        ~ConfigurationManager(void);

        static p_ConfigurationManager Instance(void);


    private:
        static p_ConfigurationManager _instance;

        ConfigurationManager(void);
        ConfigurationManager(const ConfigurationManager&) {};

        const ConfigurationManager& operator=(const ConfigurationManager& copy);
    };
}