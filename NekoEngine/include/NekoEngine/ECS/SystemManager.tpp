/*
** EPITECH PROJECT, 2021
** SystemManager
** File description:
** SystemManager
*/

/**
 * @file        SystemManager.tpp
 * @brief       System Manmager templates implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef SYSTEMMANAGER_HPP_
#ifndef SYSTEMMANAGER_TPP_
#define SYSTEMMANAGER_TPP_

#include "NekoEngine/ECS/SystemManager.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"

template<typename T>
std::shared_ptr<T> ne::SystemManager::registerSystem(std::shared_ptr<ne::Coordinator> coordinator)
{
    const char* typeName = typeid(T).name();

    if (m_systems.find(typeName) != m_systems.cend())
        throw NekoException("Cannot register a system more than once!", "");

    auto system = std::make_shared<T>();

    system->coordinator = coordinator;

    m_systems.insert({
        typeName,
        system
    });
    return (system);
}

template<typename T>
void ne::SystemManager::setSignature(ne::Signature signature)
{
    const char* typeName = typeid(T).name();

    if (m_systems.find(typeName) == m_systems.cend())
        throw NekoException("Cannot use unregistered system!", "");

    m_signatures.insert({
        typeName,
        signature
    });
}

inline void ne::SystemManager::entityDestroyed(ne::EntityID entity)
{
    for (auto const& pair : m_systems) {
        auto const& system = pair.second;
        system->m_entities.erase(entity);
    }
}

inline void ne::SystemManager::entitySignatureChanged(ne::EntityID entity, ne::Signature entitySignature)
{
    for (auto const& pair : m_systems) {
        auto const& type = pair.first;
        auto const& system = pair.second;
        auto const& systemSignature = m_signatures[type];

        if ((entitySignature & systemSignature) == systemSignature)
            system->m_entities.insert(entity);
        else
            system->m_entities.erase(entity);
    }
}

#endif
#endif /* SYSTEMMANAGER_TPP_ */