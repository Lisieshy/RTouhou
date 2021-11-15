/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameEnnemiesLoop
*/

#include "GameEnnemiesLoop.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../Game/Ennemies/Ennemies.hpp"
#include "../Game/Bullets/BulletsFactory.hpp"

uint32_t ne::GameEnnemiesLoop::update(float dt, uint32_t ID)
{
    for (auto &entity : m_entities) {
        auto& EnnemiesAlien = coordinator->getComponent<ne::Ennemies>(entity);
        if (EnnemiesAlien.isShooting(dt)) {
            auto NewEntity = coordinator->createEntity();
            std::shared_ptr<ne::Bullets> bull;
            ne::BulletsFactory bullets;
            bull = bullets.createBullets("BasicWhiteBullets");
            coordinator->addComponent(NewEntity, bull.get()->getTransform());
            coordinator->addComponent(NewEntity, bull.get()->getGravity());
            coordinator->addComponent(NewEntity, bull.get()->getRigidBody());
            coordinator->addComponent(NewEntity, ne::Renderable{});
            coordinator->addComponent(NewEntity, bull.get()->getSkin());
            coordinator->addComponent(NewEntity, bull.get()->getColor());
            coordinator->addComponent(NewEntity, ne::Uid { ID });
            ID++;
        }
    }
    return (ID);
}