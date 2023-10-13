#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Object.hpp"
#include "Tower/Entity.hpp"
#include "Tower/Rendering/Camera.hpp"
#include <vector>

namespace Tower
{
    class World
    {
    public:
        World(void);

        ~World(void);

        void Load(string filepath, p_Camera camera);

        void Update(F32 delta);

        void Render(void);

        inline void SetEntities(std::vector<p_Entity> entities)
        {
            _entities.clear();
            _entities = entities;
        }

        inline void SetObjects(std::vector<p_Object> objects)
        {
            _objects.clear();
            _objects = objects;
        }

    protected:
        p_Entity _human;
        std::vector<p_Object> _objects;
        std::vector<p_Entity> _entities;
        p_Camera _camera;

    };
    typedef shared_ptr<World> p_World;
}