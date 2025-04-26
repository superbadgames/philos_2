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
#include "Tower/Rendering/RenderEntity.hpp"

#include <vector>

namespace Tower
{
    class RenderEntityManager
    {
    public:
        ~RenderEntityManager(void);

        static shared_ptr<RenderEntityManager> Instance(void);

        p_RenderEntity GetNext(void);

        p_RenderEntity GetEntity(S32 id);

        void Render(const glm::mat4& viewMatrix);

        void ResetEntities(void);

    private:
        static shared_ptr<RenderEntityManager> _instance;
        // TODO: Move this to the DB, as a per project config.
        const S32 MAX_ENTITIES = 2000;
        S32 _nextEntity;
        std::vector<p_RenderEntity> _entities;

        RenderEntityManager(void);

        void _Init(void);

    };
    typedef shared_ptr<RenderEntityManager> p_RenderEntityManager;
}