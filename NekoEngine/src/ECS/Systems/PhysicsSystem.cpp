/*
** EPITECH PROJECT, 2021
** PhysicsSystem
** File description:
** PhysicsSystem
*/

/**
 * @file        PhysicsSystem.cpp
 * @brief       Physics System class implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/PhysicsSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/ECS/Components/RigidBody.hpp"
#include "NekoEngine/ECS/Components/Gravity.hpp"
#include <iostream>

void ne::PhysicsSystem::update(float dt)
{
    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto const& gravity = coordinator->getComponent<ne::Gravity>(entity);

        transform.position += rigidbody.velocity * dt;
        rigidbody.velocity += gravity.force * dt;
    }
}