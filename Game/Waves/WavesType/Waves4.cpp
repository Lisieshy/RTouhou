/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves4
*/

#include "Waves4.hpp"

ne::Waves4::Waves4()
{
}

ne::Waves4::~Waves4()
{
}

void ne::Waves4::LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    ne::Transform trans;
    ne::Waves2 wave2;

    wave2.LaunchWaves(ID, coordinator); 

    trans.rotation = {0.f, 0.f, 0.f};
    trans.scale = {0.f, 0.f, 0.f};
    trans.position.y = 80;
    trans.position.x = -200;
    for (int i = 0; i < 12; i++) {
        std::shared_ptr<ne::Ennemies> ennemies;
        auto NewEntity = coordinator->createEntity();

        trans.position.x += 70;
        trans.position.z = 0;
        ennemies = factory.createEnnemies("DarkBlue");
        ennemies.get()->setPattern(std::bind(&ne::Patterns::leftToRightSnakePattern, &ennemies.get()->getPattern()));
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

    trans.rotation = {0.f, 0.f, 0.f};
    trans.scale = {0.f, 0.f, 0.f};
    trans.position.y = 0;
    trans.position.x = -15;
    for (int i = 0; i < 8; i++) {
        std::shared_ptr<ne::Ennemies> ennemies;
        auto NewEntity = coordinator->createEntity();

        trans.position.x += 60;
        trans.position.y += 20;
        ennemies = factory.createEnnemies("OrangeFerry");
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

    trans.position.y = 100;
    trans.position.x = 800;
    for (int i = 0; i < 8; i++) {
        std::shared_ptr<ne::Ennemies> ennemies;
        auto NewEntity = coordinator->createEntity();

        trans.position.x -= 60;
        trans.position.y += 20;
        ennemies = factory.createEnnemies("WhiteFerry");
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
