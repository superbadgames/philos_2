/*
This is THE MAP of the Tower Engine. Every single map that is ever played will be run through this.

The map is the scene. It holds the hierarchy of nodes making up all the Entities that are rendering.

The map saves and loads the game by reading and dumping Entities into and out of database.

The database is powered by sqlite3.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Managers/RenderingManager.hpp"
#include "Tower/Objects/Player.hpp"
#include "Tower/Objects/StaticEnvironment.hpp"
#include "Tower/Objects/DynamicEnvironment.hpp"
#include "Tower/Builder/Editor.hpp"
#include "Tower/Objects/ObjectFactory.hpp"
#include "Tower/Managers/DatabaseManager.hpp"

#include <vector>

namespace Tower
{
    class DatabaseManager;
    class World;
    typedef shared_ptr<World> p_World;

    // Refactor me to be a singleton
    class World
    {
    public:
        World(void);

        virtual ~World(void);

        void Init(p_ObjectFactory factory, const string& playerType, bool createEditor);

        // TODO:
        // Until a process system has been put into place, just call
        // each of the objects created in v_Init.
        void Update(F32 delta);

        // TODO:
        // Later, when the map db is working, save the map to file
        //void SaveMap(void);

        void LoadMap(const string& name);

        void Render(void);

        inline void SetFactory(p_ObjectFactory factory) { _factory = factory; }

    protected:
        //string currentWorld;
        bool _editorActive;
        p_Player _playerOne;
        p_Player _editor;
        p_ObjectFactory _factory;
        std::vector<p_StaticEnvironmentObject> _staticEnvironment;
        std::vector<p_DynamicEnvironmentObject> _dynamicEnvironment;
        U32 _numObjectsCreated;

        static int _LoadMapDBCallback(void* inputObj, int argCount, char** argValues, char** colName);
    };
}