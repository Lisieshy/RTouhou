/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientGame
*/

#include "../include/ClientGame.hpp"

ne::ClientGame::ClientGame()
{
    ClientGameScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::EntityType::Type, ne::Patterns, rt::Controller, ne::Animation, ne::ParallaxSystem, ne::GorbBackground>();

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

    Parallax = ClientGameScene.coordinator->registerSystem<ne::ParallaxSystem>(ClientGameScene.coordinator);
    {
        ne::Signature signature;
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Skin>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::GorbBackground>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::Transform>());
        signature.set(ClientGameScene.coordinator->getComponentType<ne::ParallaxSystem>());
        ClientGameScene.coordinator->setSystemSignature<ne::ParallaxSystem>(signature);
    }
    std::vector<ne::Parallax> usine_parallax;
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,0.f,0.f), "resources/parallax/bkgd_6.png"));
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,-1000.f,0.f), "resources/parallax/bkgd_1.png"));
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,-2000.f,0.f), "resources/parallax/bkgd_2.png"));
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,-3000.f,0.f), "resources/parallax/bkgd_3.png"));
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,-4000.f,0.f), "resources/parallax/bkgd_4.png"));
    usine_parallax.push_back(ne::Parallax(ne::Math::Vector3f(0.f,-5000.f,0.f), "resources/parallax/bkgd_5.png"));
    uint32_t i = 0;
    ne::EntityID para;
    while (i != 5) {
        para = ClientGameScene.coordinator->createEntity();
        ClientGameScene.coordinator->addComponent(para, usine_parallax.at(i).getSkin());
        ClientGameScene.coordinator->addComponent(para, usine_parallax.at(i).getTransform());
        ClientGameScene.coordinator->addComponent(para, ne::GorbBackground{});
        ClientGameScene.coordinator->addComponent(para, ne::ParallaxSystem{});
        ClientGameScene.coordinator->addComponent(para, ne::Uid{i});
        i++;
        if (usine_parallax.size() == i)
            break;
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

void ne::ClientGame::Update(float dt)
{
    ClientSystem->OnMessage();
    Parallax->update(dt);
    CollisionSystem->update();
    RenderSystem->update();
    PlayerSystem->update(dt, ClientSystem);
}