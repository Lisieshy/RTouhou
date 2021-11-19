/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameEnnemiesLoop
*/

#include "GameEnnemiesLoop.hpp"


void ne::GameEnnemiesLoop::update(float dt, uint32_t& ID)
{
    for (auto &entity : m_entities) {
        auto& EnnemiesAlien = coordinator->getComponent<ne::Alien>(entity);
        auto& EnnemiesPos = coordinator->getComponent<ne::Transform>(entity);
        EnnemiesAlien.TimeToShoot -= dt;
        if (EnnemiesAlien.TimeToShoot <= 0) {
            createBullet(EnnemiesPos, ID);
            EnnemiesAlien.TimeToShoot = EnnemiesAlien.BasicTime;
            ID++;
        }
    }
}

void ne::GameEnnemiesLoop::createBullet(ne::Transform& EnnemiesPos, uint32_t& ID)
{
    auto NewEntity = coordinator->createEntity();
    std::shared_ptr<ne::Bullets> bull;
    ne::BulletsFactory bullets;
    ne::Math::Vector3f pos = EnnemiesPos.position;
    ne::Transform trans;

    pos.y += 32;
    pos.x += 8;
    trans.position = pos;
    trans.rotation = EnnemiesPos.rotation;
    trans.scale = EnnemiesPos.scale;
    bull = bullets.createBullets("BasicWhiteBullets");
    coordinator->addComponent(NewEntity, trans);
    coordinator->addComponent(NewEntity, bull.get()->getGravity());
    coordinator->addComponent(NewEntity, bull.get()->getRigidBody());
    coordinator->addComponent(NewEntity, ne::Renderable{});
    coordinator->addComponent(NewEntity, bull.get()->getType());
    coordinator->addComponent(NewEntity, ne::Uid { ID });
    coordinator->addComponent(NewEntity, ne::Networkable{});
    coordinator->addComponent(NewEntity, bull.get()->getPattern());
}
