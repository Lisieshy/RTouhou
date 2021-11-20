/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientGame
*/

#include "../include/ClientGame.hpp"

ne::ClientGame::ClientGame()
{
    ClientGameScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::EntityType::Type, ne::Patterns, rt::Controller, ne::Animation>();

    ClientSystem = ClientGameScene.coordinator->registerSystem<rt::CustomClient>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Color>());
    }

    RenderSystem = ClientGameScene.coordinator->registerSystem<ne::RenderSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Color>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Skin>());
        ClientGameScene.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    }
    PlayerSystem = ClientGameScene.coordinator->registerSystem<rt::PlayerSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::RigidBody>());
        signature.set(ClientGameScene.coordinator->getComponentType<rt::Controller>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Color>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Skin>());
        ClientGameScene.coordinator->setSystemSignature<rt::PlayerSystem>(signature);
    }
    AnimSystem = ClientGameScene.coordinator->registerSystem<ne::AnimationSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Skin>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Animation>());
        ClientGameScene.coordinator->setSystemSignature<ne::AnimationSystem>(signature);
    }

    ne::Skin playerSkin;
    playerSkin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/Ennemies/TouhouBasicMob.png"));
    playerSkin.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    ne::EntityID player = ClientGameScene.coordinator->createEntity();

    ClientGameScene.coordinator->addComponent(player, rt::Controller{
        .type = rt::ControlType::KEYBOARD,
        .up = sf::Keyboard::Key::Z,
        .down = sf::Keyboard::Key::S,
        .left = sf::Keyboard::Key::Q,
        .right = sf::Keyboard::Key::D,
        .shoot = sf::Keyboard::Key::Space,
        .speed = 20.f,
        .deadzone = 50
    });
    ClientGameScene.coordinator->addComponent(player, ne::Transform{});
    ClientGameScene.coordinator->addComponent(player, ne::RigidBody{});
    ClientGameScene.coordinator->addComponent(player, ne::Renderable{});
    ClientGameScene.coordinator->addComponent(player, ne::Color{ 255, 255, 255, 255 });
    ClientGameScene.coordinator->addComponent(player, playerSkin);
    ClientGameScene.coordinator->addComponent(player, ne::  Uid{1500});
    ClientSystem->Connect("127.0.0.1", 60000);
}

ne::ClientGame::~ClientGame()
{
}

void ne::ClientGame::InitMusic()
{
    music.openFromFile("resources/Music_SoundEffect/MainGameMusic.ogg");
    music.play();
    music.setLoop(true);
    music.setVolume(60);
}