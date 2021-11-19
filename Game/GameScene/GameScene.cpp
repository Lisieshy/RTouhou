/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameScene
*/
// Pragma definition for Windows to remove the console window.
#pragma comment(linker, "/SUBSYSTEM:windows")

#include <NekoEngine/NekoEngine.hpp>
#include <NekoEngine/Graphics/Window.hpp>
#include <random>
#include <chrono>
#include <sstream>

#include <NyaLog/NyaLog.hpp>
#include <include/CustomClient.hpp>
#include "GameScene.hpp"
#include <include/Controller.hpp>

ne::GameScene::GameScene(std::vector<ne::EntityID> &entity)
{
    entities = entity;
}

ne::GameScene::~GameScene()
{
}

void ne::GameScene::GameLoop(float dt)
{

}

void ne::GameScene::InitScene(uint32_t &entityID)
{
    Game.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::Networkable, ne::EntityType::Type, ne::Patterns>();


    PatternSystem = Game.coordinator->registerSystem<ne::PatternSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::RigidBody>());
        signature.set(Game.coordinator->getComponentType<ne::Patterns>());
        Game.coordinator->setSystemSignature<ne::PatternSystem>(signature);
    }

    EnnemiesLoopSystem = Game.coordinator->registerSystem<ne::GameEnnemiesLoop>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Alien>());
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        Game.coordinator->setSystemSignature<ne::GameEnnemiesLoop>(signature);
    }

    NetworkSystem = Game.coordinator->registerSystem<CustomServer>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::RigidBody>());
        signature.set(Game.coordinator->getComponentType<ne::Networkable>());
        Game.coordinator->setSystemSignature<CustomServer>(signature);
    }
    
    for (auto entity : entities) {
        entity = Game.coordinator->createEntity();
        std::shared_ptr<ne::Ennemies> test;

        if (entityID < 5)
            test = fact.createEnnemies("BasicPlane");
        else if (entityID < 10)
            test = fact.createEnnemies("OrangeFerry");
        else if (entityID < 15)
            test = fact.createEnnemies("GreenFerry");
        else if (entityID < 20)
            test = fact.createEnnemies("DarkBlue");
        else if (entityID < 25)
            test = fact.createEnnemies("WhiteFerry");

        Game.coordinator->addComponent(entity, test.get()->getTransform());
        Game.coordinator->addComponent(entity, test.get()->getRigidBody());
        Game.coordinator->addComponent(entity, ne::Uid{ entityID });
        Game.coordinator->addComponent(entity, test.get()->getAlien());
        Game.coordinator->addComponent(entity, test.get()->getType());
        Game.coordinator->addComponent(entity, ne::Networkable{});
        Game.coordinator->addComponent(entity, test.get()->getPattern());
        entityID++;
        if (entityID == 10)
            break;
    }

}
