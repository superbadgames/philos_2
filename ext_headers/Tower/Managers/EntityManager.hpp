#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <cassert>
#include <queue>
#include <array>

namespace Tower
{
    class EntityManager
    {
    public:
        EntityManager(void);

        ~EntityManager(void);

        EntityID CreateEntity(void);

        void DestroyEntity(EntityID entityID);

        void SetSignature(EntityID entityID, Signature signature);

        Signature GetSignature(EntityID entityID);

    private:
        // TODO: consider writing your own queue
        std::queue<EntityID> _entities;
        std::array<Signature, MAX_ENTITIES> _signatures;
        U32 _activeEntities;
    };
    typedef std::shared_ptr<EntityManager> p_EntityManager;
};