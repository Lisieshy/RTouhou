/*
** EPITECH PROJECT, 2021
** ComponentArray
** File description:
** ComponentArray
*/

/**
 * @file        ComponentArray.tpp
 * @brief       Component Array template class implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef COMPONENTARRAY_HPP_
#ifndef COMPONENTARRAY_TPP_
#define COMPONENTARRAY_TPP_

#include "NekoEngine/ECS/ComponentArray.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"

template<typename T>
void ne::ComponentArray<T>::insertData(ne::EntityID entity, T component)
{
    if (m_entityToIndex.find(entity) != m_entityToIndex.cend())
        throw ne::NekoException("Component added multiple times to the same entity!", "");

    size_t new_size = m_size;
    m_entityToIndex[entity] = new_size;
    m_IndexToEntity[new_size] = entity;
    (*m_components)[new_size] = component;
    m_size++;
}

template<typename T>
void ne::ComponentArray<T>::removeData(ne::EntityID entity)
{
    if (m_entityToIndex.find(entity) == m_entityToIndex.cend())
        throw ne::NekoException("Cannot remove non-existent component from entity!", "");

    size_t removedEntityIndex = m_entityToIndex[entity];
    size_t lastElementIndex = m_size - 1;
    (*m_components)[removedEntityIndex] = (*m_components)[lastElementIndex];

    EntityID lastElementEntity = m_IndexToEntity[lastElementIndex];
    m_entityToIndex[lastElementEntity] = removedEntityIndex;
    m_IndexToEntity[removedEntityIndex] = lastElementEntity;

    m_entityToIndex.erase(entity);
    m_IndexToEntity.erase(lastElementIndex);

    m_size--;
}

template<typename T>
T& ne::ComponentArray<T>::getData(ne::EntityID entity)
{
    if (m_entityToIndex.find(entity) == m_entityToIndex.cend())
        throw ne::NekoException("Cannot retrieve non-existent component from entity!", "");

    return ((*m_components)[m_entityToIndex[entity]]);
}

template<typename T>
void ne::ComponentArray<T>::entityDestroyed(ne::EntityID entity)
{
    if (m_entityToIndex.find(entity) != m_entityToIndex.cend())
        removeData(entity);
}

#endif
#endif /* COMPONENTARRAY_TPP_ */