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
        auto& EnnemiesAlien = coordinator->getComponent<ne::Alien>(entity);
        auto& EnnemiesPos = coordinator->getComponent<ne::Transform>(entity);
        EnnemiesAlien.TimeToShoot -= dt;
        std::cout << coordinator->getComponent<ne::Alien>(entity).TimeToShoot << " : Here is the time before shoot" << std::endl;
        if (EnnemiesAlien.TimeToShoot <= 0) {
            auto NewEntity = coordinator->createEntity();
            std::shared_ptr<ne::Bullets> bull;
            ne::BulletsFactory bullets;
            bull = bullets.createBullets("BasicWhiteBullets");
            ne::Math::Vector3f pos = EnnemiesPos.position;
            pos.y += 32;
            pos.x += 8;
            ne::Transform trans;
            trans.position = pos;
            trans.rotation = EnnemiesPos.rotation;
            trans.scale = EnnemiesPos.scale;
            coordinator->addComponent(NewEntity, trans);
            coordinator->addComponent(NewEntity, bull.get()->getGravity());
            coordinator->addComponent(NewEntity, bull.get()->getRigidBody());
            coordinator->addComponent(NewEntity, ne::Renderable{});
            coordinator->addComponent(NewEntity, bull.get()->getSkin());
            coordinator->addComponent(NewEntity, bull.get()->getColor());
            coordinator->addComponent(NewEntity, ne::Uid { ID });
            EnnemiesAlien.TimeToShoot = EnnemiesAlien.BasicTime;
            ID++;
        }
    }
    return (ID);
}

