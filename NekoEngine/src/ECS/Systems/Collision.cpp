/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Collision
*/

#include "NekoEngine/ECS/Systems/Collision.hpp"
#include "NekoEngine/ECS/Components/Components.hpp"
#include "NekoEngine/ECS/Coordinator.hpp"
#include <iostream>

void ne::Collision::update()
{
    for (auto &entity : m_entities) {
        auto& EnnemiesType = coordinator->getComponent<ne::EntityType::Type>(entity);
        if (EnnemiesType <= ne::EntityType::Type::WhiteEnnemy) {
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
            for (auto &ComparedEntity : m_entities) {
                auto& ComparedEnnemiesType = coordinator->getComponent<ne::EntityType::Type>(ComparedEntity);
                if (ComparedEnnemiesType == ne::EntityType::FriendlyBullets) {
                    auto& Comparedtransform = coordinator->getComponent<ne::Transform>(ComparedEntity);
                    if (Comparedtransform.position.x > transform.position.x && Comparedtransform.position.x < transform.position.x + 32 &&
                        Comparedtransform.position.y > transform.position.y && Comparedtransform.position.y < transform.position.y + 32) {
                        coordinator->destroyEntity(entity);
                        coordinator->destroyEntity(ComparedEntity);
                        break;
                    }
                }
            }
        }
    }
}