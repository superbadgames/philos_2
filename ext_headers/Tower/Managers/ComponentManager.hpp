#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/ComponentArray.hpp"
#include <unordered_map>
#include <memory>
#include <typeinfo>


namespace Tower
{
    class ComponentManager
    {
    public:
        ComponentManager(void) {}
        ~ComponentManager(void) {}

        template<typename T>
        void RegisterComponent(void)
        {
            const char* typeName = typeid(T).name();

            assert(_componentTypes.find(typeName) == _componentTypes.end() && "Registering component type more than once.");

            _componentTypes.insert({typeName, _nextComponentType});
            _componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

            ++_nextComponentType;
        }

        template<typename T>
        ComponentType GetComponentType(void)
        {
            const char* typeName = typeid(T).name();

            assert(_componentTypes.find(typeName) != _componentTypes.end() && "ComponentManager failed GetComponentType. No such Component registered before call.");

            return _componentTypes[typeName];
        }

        template<typename T>
        void AddComponent(Entity entity, T component)
        {
            _GetComponentArray<T>()->InsertData(entity, component);
        }

        template<typename T>
        void RemoveComponent(Entity entity)
        {
            _GetComponentArray<T>()->RemoveData(entity);
        }

        template<typename T>
        T& GetComponent(Entity entity)
        {
            return _GetComponentArray<T>()->GetData(entity);
        }

        template<typename T>
        bool HasComponent(Entity entity)
        {
            return _GetComponentArray<T>()->HasData(entity);
        }

        void EntityDestroyed(Entity entity);

    private:
        std::unordered_map<const char*, ComponentType> _componentTypes;
        std::unordered_map<const char*, p_IComponentArray> _componentArrays;
        ComponentType _nextComponentType;

        template<typename T>
        shared_ptr<ComponentArray<T>> _GetComponentArray(void)
        {
            const char* typeName = typeid(T).name();

            assert(_componentTypes.find(typeName) != _componentTypes.end() && "ComponentManager failed _GetComponentArray. No Components registered.");

            return std::static_pointer_cast<ComponentArray<T>>(_componentArrays[typeName]);
        }
    };
}