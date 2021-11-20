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
#include <NekoEngine/NekoEngine.hpp>
#include <NyaLog/NyaLog.hpp>
#include <iostream>
#include <random>

void ne::PatternSystem::update(float& dt)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 800);
    std::vector<ne::EntityID> enemyToBeDestroyed;
    std::vector<ne::EntityID> bulletsToBeDestroyed;

    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto& pattern = coordinator->getComponent<ne::Patterns>(entity);
        transform.position += pattern.patternFunc() * (dt / 2);
        if (transform.position.y > 600.f) {
            if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::WhiteEnnemy)
                enemyToBeDestroyed.push_back(entity);
            else if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::Bullets)
                bulletsToBeDestroyed.push_back(entity);
        }
    }
    for (auto &enemyDestroyed : enemyToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(enemyDestroyed);
        coordinator->removeComponent<ne::Gravity>(enemyDestroyed);
        coordinator->removeComponent<ne::RigidBody>(enemyDestroyed);
        coordinator->removeComponent<ne::Renderable>(enemyDestroyed);
        coordinator->removeComponent<ne::Uid>(enemyDestroyed);
        coordinator->removeComponent<ne::Alien>(enemyDestroyed);
        coordinator->removeComponent<ne::Networkable>(enemyDestroyed);
        coordinator->removeComponent<ne::EntityType::Type>(enemyDestroyed);
        coordinator->removeComponent<ne::Patterns>(enemyDestroyed);
        coordinator->destroyEntity(enemyDestroyed);
    }
    for (auto &bulletDestroyed : bulletsToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(bulletDestroyed);
        coordinator->removeComponent<ne::Gravity>(bulletDestroyed);
        coordinator->removeComponent<ne::RigidBody>(bulletDestroyed);
        coordinator->removeComponent<ne::Renderable>(bulletDestroyed);
        coordinator->removeComponent<ne::Uid>(bulletDestroyed);
        coordinator->removeComponent<ne::Networkable>(bulletDestroyed);
        coordinator->removeComponent<ne::EntityType::Type>(bulletDestroyed);
        coordinator->removeComponent<ne::Patterns>(bulletDestroyed);
        coordinator->destroyEntity(bulletDestroyed);
    }
}