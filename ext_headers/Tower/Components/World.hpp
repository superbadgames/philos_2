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

#include <vector>

namespace Tower
{
    class World;
    typedef shared_ptr<World> p_World;

    // Refactor me to be a singleton
    class World
    {
    public:
        World(void);

        virtual ~World(void);

        // TODO:
        // Filepath to a database
        // Database reading function
        //void ChangeMap(const string& filepath);
        // For now, I don't have the data base working yet, so
        // just make the maps like before, an interface, with
        // a list of objects to make. Use the entity manager,
        // and let the map do all the magic from there
        // By magic, I mean that each object defined in the
        // Project will have an _entity handle, and that will
        // be used for all the rendering.
        virtual void v_Init(void) = 0;

        // TODO:
        // Until a process system has been put into place, just call
        // each of the objects created in v_Init.
        void Update(F32 delta);

        // TODO:
        // Later, when the map db is working, save the map to file
        //void SaveMap(void);

        void Render(void);

    protected:
        //string currentWorld;
        bool _editorActive;
        p_Player _playerOne;
        p_Player _editor;
        std::vector<p_StaticEnvironmentObject> _staticEnvironment;
        std::vector<p_DynamicEnvironmentObject> _dynamicEnvironment;
    };
}