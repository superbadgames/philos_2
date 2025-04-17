/*

A manager for the 3D models that are loaded into that game.

The goal of this manager is to save on resources. By only loading a model once,
memory can be saved.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Model.hpp"

#include <map>

namespace Tower
{
    class ModelManager
    {
    public:
        ~ModelManager(void);

        static shared_ptr<ModelManager> Instance(void);

        void Add(const string& name, p_Model model);

        void Load(const string& name, const string& filepath, p_Shader shader);

        void Remove(const string& name);

        p_Model Get(const string& name);


    private:
        ModelManager(void);

        static shared_ptr<ModelManager> _instance;
        std::map<string, p_Model> _modelRegistry;

    };
    typedef shared_ptr<ModelManager> p_ModelManager;
}