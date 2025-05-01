/*

The Entity Manager:

This could have many names. It is the main container of all the Entities in the game.

It is a Singleton.

It statically allocates MAX_ENTITIES entities into a vector, element index is the Entity::ID for each entity in the vector.
No new entities are ever created.

The Manager also iterates over each entity to call Render

*/
# pragma once
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"

#include <vector>

namespace Tower
{
    class RenderingManager;
    typedef shared_ptr<RenderingManager> p_RenderingManager;

    class RenderingManager
    {
    public:
        ~RenderingManager(void);

        static shared_ptr<RenderingManager> Instance(void);

        p_Renderer GetNext(void);

        p_Renderer GetEntity(S32 id);

        void Render(const glm::mat4& viewMatrix);

        void ResetEntities(void);

    private:
        static shared_ptr<RenderingManager> _instance;
        // TODO: Move this to the DB, as a per project config.
        const S32 MAX_RENDERING = 2000;
        S32 _nextRenderer;
        std::vector<p_Renderer> _renderings;

        RenderingManager(void);

        void _Init(void);
    };
}