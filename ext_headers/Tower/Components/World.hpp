/*
This is THE MAP of the Tower Engine. Every single map that is ever played will be run through this.

The map is the scene. It holds the hierarchy of nodes making up all the Entities that are rendering.

The map saves and loads the game by reading and dumping Entities into and out of database.

The database is powered by sqlite3.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/EntityManager.hpp"
#include "Tower/Cameras/Camera.hpp"


#include <map>

namespace Tower
{
    class World;
    typedef shared_ptr<World> p_World;

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
        virtual void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) = 0;

        // TODO:
        // Until a process system has been put into place, just call
        // each of the objects created in v_Init.
        virtual void v_Update(F32 delta) = 0;

        // TODO:
        // Later, when the map db is working, save the map to file
        //void SaveMap(void);

        void Render(void);

        inline void SetCamera(p_Camera camera) { _camera = camera; }

    protected:
        //string currentWorld;
        p_Camera _camera;

    };
}