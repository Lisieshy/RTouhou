/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BonusSystem
*/

#include "NekoEngine/ECS/Systems/BonusSystem.hpp"

void ne::BonusSystem::update(float dt, uint32_t &ID)
{
    Time -= dt;
    if (Time <= 0) {
        Time = 1.0f;
        auto NewEntity = coordinator->createEntity();
        std::shared_ptr<ne::Bonus> bonus;

        bonus = bonusFact.createBonus("ScoreUp");
        coordinator->addComponent(NewEntity, bonus.get()->getPattern());
        coordinator->addComponent(NewEntity, bonus.get()->getTransform());
        coordinator->addComponent(NewEntity, bonus.get()->getType());
        coordinator->addComponent(NewEntity, ne::RigidBody{});
        coordinator->addComponent(NewEntity, ne::Networkable{});
        coordinator->addComponent(NewEntity, ne::Uid{ ID });
    }
}