/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientGame
*/

#include "../include/ClientGame.hpp"

ne::ClientGame::ClientGame()
{
    ClientGameScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin, ne::Uid, ne::Alien, ne::EntityType::Type, ne::Patterns>();

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

    ClientSystem->Connect("127.0.0.1", 60000);
}

ne::ClientGame::~ClientGame()
{
}
