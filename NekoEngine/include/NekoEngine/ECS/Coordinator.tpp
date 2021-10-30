/*
** EPITECH PROJECT, 2021
** Coordinator
** File description:
** Coordinator
*/

/**
 * @file        Coordinator.tpp
 * @brief       Coordinator templates implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef COORDINATOR_HPP_
#ifndef COORDINATOR_TPP_
#define COORDINATOR_TPP_

#include "NekoEngine/ECS/Coordinator.hpp"

inline void ne::Coordinator::init()
{
    m_componentManager = std::make_unique<ne::ComponentManager>();
    m_entityManager = std::make_unique<ne::EntityManager>();
    m_systemManager = std::make_unique<ne::SystemManager>();
}

inline ne::EntityID ne::Coordinator::createEntity()
{
    return m_entityManager->createEntity();
}

inline void ne::Coordinator::destroyEntity(ne::EntityID entity)
{
    m_entityManager->destroyEntity(entity);
    m_componentManager->entityDestroyed(entity);
    m_systemManager->entityDestroyed(entity);
}

template<typename T, typename ...Ts>
void ne::Coordinator::registerComponent()
{
    m_componentManager->registerComponent<T>();

    if constexpr (sizeof...(Ts) > 0) {
        registerComponent<Ts...>();
    }
}

template<typename T>
void ne::Coordinator::addComponent(ne::EntityID entity, T component)
{
    m_componentManager->addComponent<T>(entity, component);

    auto signature = m_entityManager->getSignature(entity);
    signature.set(m_componentManager->getComponentType<T>(), true);
    m_entityManager->setSignature(entity, signature);

    m_systemManager->entitySignatureChanged(entity, signature);
}

template<typename T>
void ne::Coordinator::removeComponent(ne::EntityID entity)
{
    m_componentManager->removeComponent<T>(entity);

    auto signature = m_entityManager->getSignature(entity);
    signature.set(m_componentManager->getComponentType<T>(), false);
    m_entityManager->setSignature(entity, signature);

    m_systemManager->entitySignatureChanged(entity, signature);
}

template<typename T>
T& ne::Coordinator::getComponent(ne::EntityID entity)
{
    return m_componentManager->getComponent<T>(entity);
}

template<typename T>
ne::ComponentType ne::Coordinator::getComponentType()
{
    return m_componentManager->getComponentType<T>();
}

template<typename T>
std::shared_ptr<T> ne::Coordinator::registerSystem(std::shared_ptr<ne::Coordinator> coordinator)
{
    return m_systemManager->registerSystem<T>(coordinator);
}

template<typename T>
void ne::Coordinator::setSystemSignature(ne::Signature signature)
{
    m_systemManager->setSignature<T>(signature);
}

#endif
#endif /* COORDINATOR_HPP */