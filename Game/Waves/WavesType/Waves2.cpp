/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves2
*/

#include "Waves2.hpp"

ne::Waves2::Waves2()
{
}

ne::Waves2::~Waves2()
{
}


void ne::Waves2::LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    ne::Transform trans;

    trans.rotation = {0.f, 0.f, 0.f};
    trans.scale = {0.f, 0.f, 0.f};
    trans.position.y = 0;
    trans.position.x = -200;
    for (int i = 0; i < 9; i++) {
        std::shared_ptr<ne::Ennemies> ennemies;
        auto NewEntity = coordinator->createEntity();

        trans.position.x += 60;
        trans.position.z = 0;
        ennemies = factory.createEnnemies("DarkBlue");
        coordinator->addComponent(NewEntity, trans);
        coordinator->addComponent(NewEntity, ennemies.get()->getGravity());
        coordinator->addComponent(NewEntity, ennemies.get()->getRigidBody());
        coordinator->addComponent(NewEntity, ne::Renderable{});
        coordinator->addComponent(NewEntity, ne::Uid { ID });
        coordinator->addComponent(NewEntity, ennemies.get()->getAlien());
        coordinator->addComponent(NewEntity, ne::Networkable{});  
        coordinator->addComponent(NewEntity, ennemies.get()->getType());  
        coordinator->addComponent(NewEntity, ennemies.get()->getPattern());  
        ID++;
    }

    trans.position.y = 200;
    trans.position.x = 1000;
    for (int i = 0; i < 9; i++) {
        std::shared_ptr<ne::Ennemies> ennemies;
        auto NewEntity = coordinator->createEntity();

        trans.position.x -= 60;
        trans.position.z = 0;
        ennemies = factory.createEnnemies("GreenFerry");
        coordinator->addComponent(NewEntity, trans);
        coordinator->addComponent(NewEntity, ennemies.get()->getGravity());
        coordinator->addComponent(NewEntity, ennemies.get()->getRigidBody());
        coordinator->addComponent(NewEntity, ne::Renderable{});
        coordinator->addComponent(NewEntity, ne::Uid { ID });
        coordinator->addComponent(NewEntity, ennemies.get()->getAlien());
        coordinator->addComponent(NewEntity, ne::Networkable{});  
        coordinator->addComponent(NewEntity, ennemies.get()->getType());  
        coordinator->addComponent(NewEntity, ennemies.get()->getPattern());  
        ID++;
    }
}