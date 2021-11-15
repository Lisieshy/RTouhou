/*
** EPITECH PROJECT, 2021
** EntityManager
** File description:
** EntityManager
*/

/**
 * @file        EntityManager.cpp
 * @brief       Contains the implementation of the Entity Manager.
 * @details     ECS are good. ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#include "NekoEngine/ECS/EntityManager.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"
#include <iostream>

ne::EntityManager::EntityManager()
{
    for (ne::EntityID entity = 0; entity <= ne::MAX_ENTITIES; ++entity) {
        m_availableEntities.push(entity);
    }
}

ne::EntityID ne::EntityManager::createEntity()
{
    if (m_livingEntities >= MAX_ENTITIES)
        throw ne::NekoException("Failed to create new entity!", "No more entity IDs available!");

    ne::EntityID id = m_availableEntities.front();
    m_availableEntities.pop();
    m_livingEntities++;
    return (id);
}

void ne::EntityManager::destroyEntity(ne::EntityID entity)
{
    if (entity >= MAX_ENTITIES)
        throw ne::NekoException("Failed to destroy entity!", "Entity is invalid (out of range)");

    (*m_signatures)[entity].reset();
    m_availableEntities.push(entity);
    m_livingEntities--;
}

void ne::EntityManager::setSignature(ne::EntityID entity, ne::Signature signature)
{
    if (entity >= MAX_ENTITIES)
        throw ne::NekoException("Failed to set signature!", "Entity is invalid (out of range)");

    (*m_signatures)[entity] = signature;
}

ne::Signature ne::EntityManager::getSignature(ne::EntityID entity)
{
    if (entity >= MAX_ENTITIES)
        throw ne::NekoException("Failed to get signature!", "Entity is invalid (out of range)");

    return ((*m_signatures)[entity]);
}
