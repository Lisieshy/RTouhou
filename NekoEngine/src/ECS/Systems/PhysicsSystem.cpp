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
#include <random>

void ne::PhysicsSystem::update(float dt)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 800);

    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto const& gravity = coordinator->getComponent<ne::Gravity>(entity);

        transform.position += rigidbody.velocity * dt;
        rigidbody.velocity += gravity.force * dt;
        if (transform.position.y > 600) {
            transform.position.y = 0;
            transform.position.x = static_cast<float>(distrib(gen));
        }
        if (rigidbody.velocity.y > 100) {
            rigidbody.velocity.y = 100;
        }
    }
}