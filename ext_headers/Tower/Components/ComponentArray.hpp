#pragma once
#include "pch.h"
#include "Tower/framework.h"


#include <array>
#include <unordered_map>
#include <cassert>
#include <cstddef>

namespace Tower
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void v_EntityDestroyed(Entity entity)=0;
    };
    typedef shared_ptr<IComponentArray> p_IComponentArray;

    template<typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        ComponentArray(void)
        :
        _componentArray{},
        _entityToIndex{},
        _indexToEntity{},
        _nextIndex(0)
        {

        }

        ~ComponentArray(void)
        {

        }

        void InsertData(Entity entity, T component)
        {
            assert(_entityToIndex.find(entity) == _entityToIndex.end() && "ComponentArray failed InsertData! Duplicate call made!");

            size_t index = _nextIndex;
            _entityToIndex[entity] = index;
            _indexToEntity[index] = entity;
            _componentArray[index] = component;
            ++_nextIndex;
        }

        void RemoveData(Entity entity)
        {
            assert(_entityToIndex.find(entity) != _entityToIndex.end() && "ComponentArray failed RemoveData! No such Entity!");

            size_t indexRemoved = _entityToIndex[entity];
            size_t indexLastElement = _nextIndex - 1;
            _componentArray[indexRemoved] = _componentArray[indexLastElement];

            Entity entityLastElement = _indexToEntity[indexLastElement];
            _entityToIndex[entityLastElement] = indexRemoved;
            _indexToEntity[indexRemoved] = entityLastElement;

            --_nextIndex;
        }


        T& GetData(Entity entity)
        {
           assert(HasData(entity) && "ComponentArray failed GetData! No such Entity!");
            return _componentArray[entity];
        }

        bool HasData(Entity entity)
        {
            if(_entityToIndex.find(entity) != _entityToIndex.end())
            {
                return true;
            }

            return false;
        }

        void v_EntityDestroyed(Entity entity) override
        {
            if(_entityToIndex.find(entity) != _entityToIndex.end())
            {
                RemoveData(entity);
            }
        }

        inline std::size_t GetCount(void)
        {
            return _nextIndex;
        }

    private:
        std::array<T, MAX_ENTITIES> _componentArray;
        std::unordered_map<Entity, size_t> _entityToIndex;
        std::unordered_map<size_t, Entity> _indexToEntity;
        std::size_t _nextIndex;
    };
}