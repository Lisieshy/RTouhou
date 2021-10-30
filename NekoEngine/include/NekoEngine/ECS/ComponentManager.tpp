/*
** EPITECH PROJECT, 2021
** ComponentManager
** File description:
** ComponentManager
*/

/**
 * @file        ComponentManager.tpp
 * @brief       Component Manmager templates implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef COMPONENTMANAGER_HPP_
#ifndef COMPONENTMANAGER_TPP_
#define COMPONENTMANAGER_TPP_

#include "NekoEngine/ECS/ComponentManager.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"

template<typename T>
void ne::ComponentManager::registerComponent()
{
    const char* typeName = typeid(T).name();

    if (m_componentTypes.find(typeName) != m_componentTypes.cend())
        throw NekoException("Cannot register component type more than once!", "");

    m_componentTypes.insert({
        typeName,
        m_nextComponentType
    });

    m_componentArrays.insert({
        typeName,
        std::make_shared<ComponentArray<T>>()
    });

    m_nextComponentType++;
}

template<typename T>
ne::ComponentType ne::ComponentManager::getComponentType()
{
    const char* typeName = typeid(T).name();

    if (m_componentTypes.find(typeName) == m_componentTypes.cend())
        throw NekoException("Component needs to be registered before use!", "");

    return (m_componentTypes[typeName]);
}

template<typename T>
void ne::ComponentManager::addComponent(ne::EntityID entity, T component)
{
    getComponentArray<T>()->insertData(entity, component);
}

template<typename T>
void ne::ComponentManager::removeComponent(ne::EntityID entity)
{
    getComponentArray<T>()->removeData(entity);
}

template<typename T>
T& ne::ComponentManager::getComponent(ne::EntityID entity)
{
    return getComponentArray<T>()->getData(entity);
}

inline void ne::ComponentManager::entityDestroyed(ne::EntityID entity)
{
    for (auto const& pair : m_componentArrays) {
        auto const& component = pair.second;
        component->entityDestroyed(entity);
    }
}

template<typename T>
std::shared_ptr<ne::ComponentArray<T>> ne::ComponentManager::getComponentArray()
{
    const char* typeName = typeid(T).name();

    if (m_componentTypes.find(typeName) == m_componentTypes.cend())
        throw NekoException("Component needs to be registered before use!", "");

    return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[typeName]);
}

#endif
#endif /* COMPONENTMANAGER_TPP_ */