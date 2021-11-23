/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves1
*/

#include "Waves1.hpp"

ne::Waves1::Waves1()
{

}

ne::Waves1::~Waves1()
{

}

void ne::Waves1::LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    ne::Transform trans;

    trans.rotation = {0.f, 0.f, 0.f};
    trans.scale = {0.f, 0.f, 0.f};
    trans.position.y = -100;
    for (int y = 0; y < 3; y++) {
        trans.position.y += 46;
        for (int i = 0; i < 12; i++) {
            std::shared_ptr<ne::Ennemies> ennemies;
            auto NewEntity = coordinator->createEntity();

            trans.position.x = 45;
            trans.position.x += 60 * i;
            trans.position.z = 0;
            ennemies = factory.createEnnemies("BasicPlane");
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
}