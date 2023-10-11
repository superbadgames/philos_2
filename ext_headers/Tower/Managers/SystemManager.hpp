#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/System.hpp"
#include <unordered_map>
#include <memory>

namespace Tower
{
    class SystemManager
    {
    public:
        SystemManager(void);

        ~SystemManager(void);

        template<typename T>
        shared_ptr<T> RegisterSystem(void)
        {
           const char* typeName = typeid(T).name();

            assert(_systems.find(typeName) == _systems.end() && "Don't call RegisterSystem more than once per System.");

            auto system = std::make_shared<T>();
            _systems.insert({typeName, system});
            return system;
        }

        // TODO: I have some ideas about this. It seems like the guide may have some flaws in it. This is... unexpected.
        // I considered making this smart, but I may not be 100% following all of this logic. But... there may be a chance
        // to optimize here. The assert below could be swapped out with an if, and if the system isn't registered... well
        // go ahead and register it now. Just a thought
        template<typename T>
        void SetSignature(Signature signature)
        {
            const char* typeName = typeid(T).name();
            assert(_systems.find(typeName) != _systems.end() && "SystemManager failed SetSignature. No such System.");

            _signatures.insert({typeName, signature});
        }

        void EntityDestroyed(Entity entity);

        void EntitySignatureChanged(Entity entity, Signature entitySignature);

    private:
        std::unordered_map<const char*, Signature> _signatures {};
        std::unordered_map<const char*, p_System> _systems{};
    };
}