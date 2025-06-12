#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/DatabaseManager.hpp"

#include <map>

namespace Tower
{
    class ConfigurationManager;
    typedef shared_ptr<ConfigurationManager> p_ConfigurationManager;

    class ConfigurationManager
    {
    public:
        ~ConfigurationManager(void);

        static p_ConfigurationManager Instance(void);

        void LoadConfigsFromDB(void);

        void AddConfigUINT(const string& name, U32 value);

        void AddConfigINT(const string& name, S32 value);

        void AddConfigFLOUT(const string& name, F32 value);

        void AddConfigString(const string& name, const string& value);

        U32 GetConfigUINT(const string& name);

        S32 GetConfigINT(const string& name);

        F32 GetConfigFLOUT(const string& name);

        const string& GetConfigString(const string& name);

    private:
        static p_ConfigurationManager _instance;
        string _empty;
        std::map<string, U32> _u32Configs;
        std::map<string, S32> _s32Configs;
        std::map<string, F32> _f32Configs;
        std::map<string, string> _stringConfigs;

        ConfigurationManager(void);
        ConfigurationManager(const ConfigurationManager&) {};

        const ConfigurationManager& operator=(const ConfigurationManager& copy);

        static int _dbCallback(void* inputObj, int argCount, char** argValues, char** colName);

    };
}