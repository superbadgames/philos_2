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
#include "Tower/Managers/ConfigurationManager.hpp"
#include "Tower/Rendering/Renderer.hpp"

#include <vector>

namespace Tower
{
    class RenderingSystem;
    typedef shared_ptr<RenderingSystem> p_RenderingSystem;

    class RenderingSystem
    {
    public:
        ~RenderingSystem(void);

        static shared_ptr<RenderingSystem> Instance(void);

        p_Renderer GetNext(void);

        p_Renderer GetEntity(U32 id);

        void Render(const glm::mat4& viewMatrix);

        void ResetEntities(void);

    private:
        static shared_ptr<RenderingSystem> _instance;
        // Treat as const. It will only change if a base decision is made
        U32 MAX_ENTITIES;
        U32 _nextRenderer;
        std::vector<p_Renderer> _renders;

        RenderingSystem(void);

        void _Init(void);
    };
}