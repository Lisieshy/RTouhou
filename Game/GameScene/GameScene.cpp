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
#include <include/Controller.hpp>

ne::GameScene::GameScene(std::vector<ne::EntityID>& Entity)
{
    entities = Entity;
}

ne::GameScene::~GameScene()
{
}

void ne::GameScene::GameLoop(float dt)
{

}

void ne::GameScene::setEntity(uint32_t ID)
{
    entityID = ID;
}

uint32_t ne::GameScene::getEntity()
{
    return (entityID);
}

void ne::GameScene::InitScene()
{
    Game.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, rt::Controller, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::EntityType::Type, ne::Patterns>();

    RenderSystem = Game.coordinator->registerSystem<ne::RenderSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::Renderable>());
        signature.set(Game.coordinator->getComponentType<ne::Color>());
        signature.set(Game.coordinator->getComponentType<ne::Skin>());
        Game.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    }

    PatternSystem = Game.coordinator->registerSystem<ne::PatternSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::RigidBody>());
        signature.set(Game.coordinator->getComponentType<ne::Patterns>());
        Game.coordinator->setSystemSignature<ne::PatternSystem>(signature);
    }

    ClientSystem = Game.coordinator->registerSystem<rt::CustomClient>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::Renderable>());
        signature.set(Game.coordinator->getComponentType<ne::Color>());
        Game.coordinator->setSystemSignature<ne::PatternSystem>(signature);
    }

    EnnemiesLoopSystem = Game.coordinator->registerSystem<ne::GameEnnemiesLoop>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Alien>());
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        Game.coordinator->setSystemSignature<ne::GameEnnemiesLoop>(signature);
    }

    PlayerSystem = Game.coordinator->registerSystem<rt::PlayerSystem>(Game.coordinator);
    {
        ne::Signature signature;
        signature.set(Game.coordinator->getComponentType<ne::Transform>());
        signature.set(Game.coordinator->getComponentType<ne::RigidBody>());
        signature.set(Game.coordinator->getComponentType<rt::Controller>());
        signature.set(Game.coordinator->getComponentType<ne::Renderable>());
        signature.set(Game.coordinator->getComponentType<ne::Color>());
        signature.set(Game.coordinator->getComponentType<ne::Skin>());
        Game.coordinator->setSystemSignature<rt::PlayerSystem>(signature);
    }

    ClientSystem->Connect("127.0.0.1", 60000);

    ne::EntityID player = Game.coordinator->createEntity();

    ne::Skin playerSkin;
    playerSkin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/Ennemies/TouhouBasicMob.png"));
    playerSkin.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

    Game.coordinator->addComponent(player, rt::Controller{
        .type = rt::ControlType::KEYBOARD,
        .up = sf::Keyboard::Key::Z,
        .down = sf::Keyboard::Key::S,
        .left = sf::Keyboard::Key::Q,
        .right = sf::Keyboard::Key::D,
        .shoot = sf::Keyboard::Key::Space,
        .speed = 20.f,
        .deadzone = 50
    });
    Game.coordinator->addComponent(player, ne::Transform{});
    Game.coordinator->addComponent(player, ne::RigidBody{});
    Game.coordinator->addComponent(player, ne::Renderable{});
    Game.coordinator->addComponent(player, ne::Color{ 255, 255, 255, 255 });
    Game.coordinator->addComponent(player, playerSkin);
    Game.coordinator->addComponent(player, ne::Uid{1500});


    // for (auto entity : entities) {
    //     entity = Game.coordinator->createEntity();
    //     std::shared_ptr<ne::Ennemies> test;

    //     if (entityID < 5)
    //         test = fact.createEnnemies("BasicPlane");
    //     else if (entityID < 10)
    //         test = fact.createEnnemies("OrangeFerry");
    //     else if (entityID < 15)
    //         test = fact.createEnnemies("GreenFerry");
    //     else if (entityID < 20)
    //         test = fact.createEnnemies("DarkBlue");
    //     else if (entityID < 25)
    //         test = fact.createEnnemies("WhiteFerry");

    //     if (entityID < 25) {
    //         Game.coordinator->addComponent(entity, test.get()->getTransform());
    //         Game.coordinator->addComponent(entity, test.get()->getGravity());
    //         Game.coordinator->addComponent(entity, test.get()->getRigidBody());
    //         Game.coordinator->addComponent(entity, ne::Renderable{});
    //         Game.coordinator->addComponent(entity, test.get()->getColor());
    //         Game.coordinator->addComponent(entity, test.get()->getSkin());
    //         Game.coordinator->addComponent(entity, ne::Uid{ entityID });
    //         Game.coordinator->addComponent(entity, test.get()->getAlien());
    //         Game.coordinator->addComponent(entity, test.get()->getType());
    //     }
    //     EnnemiesAlive.insert({ entityID, test });
    //     entityID++;
    //     if (entityID == 10)
    //         break;
    // }
}
