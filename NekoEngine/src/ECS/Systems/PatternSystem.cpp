/*
** EPITECH PROJECT, 2021
** PatternSystem
** File description:
** PatternSystem
*/

/**
 * @file        PatternSystem.cpp
 * @brief       Physics System class implementation
 * @details     ECS are fun, ECS are life.
 * @author      Eliott Ferry (@Gidorah)
 * @date        16/11/2021
 */

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/PatternSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/ECS/Components/RigidBody.hpp"
#include "NekoEngine/ECS/Components/Patterns.hpp"
#include <NyaLog/NyaLog.hpp>
#include <iostream>
#include <random>

void ne::PatternSystem::update(float dt)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 800);

    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto& pattern = coordinator->getComponent<ne::Patterns>(entity);
        transform.position += pattern.patternFunc() * (dt / 2);
        if (transform.position.y > 600.f) {
            transform.position.y = 0.f;
            transform.position.x = static_cast<float>(distrib(gen));
        }
        if (transform.position.y <= 0.f) {
            transform.position.y = 600.f;
            transform.position.x = static_cast<float>(distrib(gen));
        }
        if (transform.position.x <= 0.f) {
            transform.position.x = 800.f;
            transform.position.y = static_cast<float>(distrib(gen));
        }
        if (transform.position.x > 800.f) {
            transform.position.y = 0.f;
            transform.position.x = static_cast<float>(distrib(gen));
        }
    }
}