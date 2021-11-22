/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientGame
*/

#include "../include/ClientGame.hpp"

ne::ClientGame::ClientGame()
{
    ClientGameScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::EntityType::Type, ne::Patterns, rt::Controller, ne::Animation, ne::Textinfo>();

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
        signature.set(ClientGameScene.coordinator->getComponentType<rt::Controller>());
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

    CollisionSystem = ClientGameScene.coordinator->registerSystem<ne::ClientCollision>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::EntityType::Type>());
        ClientGameScene.coordinator->setSystemSignature<ne::ClientCollision>(signature);        
    }

    WavesSystemClient = ClientGameScene.coordinator->registerSystem<ne::WavesClientSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Textinfo>());
        ClientGameScene.coordinator->setSystemSignature<ne::WavesClientSystem>(signature);        
    }

    TextSystemClient = ClientGameScene.coordinator->registerSystem<ne::TextSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Textinfo>());
        ClientGameScene.coordinator->setSystemSignature<ne::TextSystem>(signature);        
    }

    ne::Skin playerSkin;
    playerSkin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/Player/reimu.png"));
    playerSkin.sprite.setTextureRect(sf::IntRect(0, 0, 32, 50));
    ClientSystem->_player = ClientGameScene.coordinator->createEntity();

    ClientSystem->Connect("127.0.0.1", 60000);   
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, rt::Controller{
        .type = rt::ControlType::KEYBOARD,
        .up = sf::Keyboard::Key::Z,
        .down = sf::Keyboard::Key::S,
        .left = sf::Keyboard::Key::Q,
        .right = sf::Keyboard::Key::D,
        .shoot = sf::Keyboard::Key::Space,
        .speed = 60.f,
        .deadzone = 50
    });
    ne::Transform transformPlayer;
    transformPlayer.position = { 350.f, 500.f, 0.f };
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, transformPlayer);
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, ne::RigidBody{});
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, ne::Renderable{});
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, ne::Color{ 255, 255, 255, 255 });
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, playerSkin);
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, ne::Animation{});
    ClientGameScene.coordinator->addComponent(ClientSystem->_player, ne::EntityType::Type { ne::EntityType::Type::Player });
}

ne::ClientGame::~ClientGame()
{
}

void ne::ClientGame::InitMusic()
{
    music.openFromFile("resources/Music_SoundEffect/MainGameMusic.ogg");
    music.play();
    music.setLoop(true);
    music.setVolume(30);
}