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
#include "../../Game/Ennemies/EnnemiesFactory.hpp"
#include "../../Game/Bullets/BulletsFactory.hpp"
#include "GameScene.hpp"

ne::GameScene::GameScene(std::vector<ne::EntityID> Entity)
{
    entities = Entity;
}

ne::GameScene::~GameScene()
{
}

void ne::GameScene::GameLoop()
{
    InitScene();
}

void ne::GameScene::InitScene()
{
    Game.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid>();

    RenderSystem = Game.coordinator->registerSystem<ne::RenderSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::Renderable>());
        signature.set(Game.coordinator->getComponentType<ne::Color>());
        signature.set(Game.coordinator->getComponentType<ne::Skin>());
        Game.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    }

    PhysicsSystem = Game.coordinator->registerSystem<ne::PhysicsSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::RigidBody>());
        signature.set(Game.coordinator->getComponentType<ne::Gravity>());
        Game.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }

    ClientSystem = Game.coordinator->registerSystem<rt::CustomClient>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::Renderable>());
        signature.set(Game.coordinator->getComponentType<ne::Color>());
        Game.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }

    ClientSystem->Connect("127.0.0.1", 60000);

    for (auto entity : entities) {
        entity = Game.coordinator->createEntity();
        std::shared_ptr<ne::Ennemies> test;
        std::shared_ptr<ne::Bullets> bull;

        if (entityID < 5)
            test = fact.createEnnemies("BasicPlane");
        else if (entityID < 10)
            test = fact.createEnnemies("DarkBlue");
        else if (entityID < 15)
            test = fact.createEnnemies("GreenFerry");
        else if (entityID < 20)
            test = fact.createEnnemies("OrangeFerry");
        else if (entityID < 25)
            test = fact.createEnnemies("WhiteFerry");
        else
            bull = bullets.createBullets("BasicWhiteBullets");
        
        if (entityID < 25) {
            Game.coordinator->addComponent(entity, test.get()->getTransform());
            Game.coordinator->addComponent(entity, test.get()->getGravity());
            Game.coordinator->addComponent(entity, test.get()->getRigidBody());
            Game.coordinator->addComponent(entity, ne::Renderable{});
            Game.coordinator->addComponent(entity, test.get()->getColor());
            Game.coordinator->addComponent(entity, test.get()->getSkin());
            Game.coordinator->addComponent(entity, ne::Uid{ entityID });
        } else {
            Game.coordinator->addComponent(entity, bull.get()->getTransform());
            Game.coordinator->addComponent(entity, bull.get()->getGravity());
            Game.coordinator->addComponent(entity, bull.get()->getRigidBody());
            Game.coordinator->addComponent(entity, ne::Renderable{});
            Game.coordinator->addComponent(entity, bull.get()->getColor());
            Game.coordinator->addComponent(entity, bull.get()->getSkin());
            Game.coordinator->addComponent(entity, ne::Uid{ entityID });           
        }
        entityID++;
        if (entityID == 30)
            break;
    }
}
