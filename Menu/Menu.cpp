/*
** EPITECH PROJECT, 2021
** Menu.cpp
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

ne::Menu::Menu()
{
    if (!skin.texture.loadFromFile("resources/menu.png"))
        throw std::runtime_error("Error, couldn't load resources/bg.jpg");
    grav.force = ne::Math::Vector3f(0.f,0.f,0.f);
    transf.position = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.scale = ne::Math::Vector3f{0.f, 0.f, 0.f};
    rigid.acceleration = ne::Math::Vector3f{0.f, 0.f, 0.f};
    rigid.velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    skin.sprite.setTexture(skin.texture);
    skin.sprite.setScale({1.5, 1.5});
    temp = {0, 0, 0, 0};
}

ne::Menu::~Menu()
{
}

ne::Transform ne::Menu::getTransform()
{
    return (transf);
}

ne::Gravity ne::Menu::getGravity()
{
    return (grav);
}

ne::RigidBody ne::Menu::getRigidBody()
{
    return (rigid);
}

ne::Color ne::Menu::getColor()
{
    return (temp);
}

ne::Skin ne::Menu::getSkin()
{
    return (skin);
}

ne::Scene ne::Menu::getScene()
{
    scene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin>();
    Rendering = scene.coordinator->registerSystem<ne::RenderSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Transform>());
        sign.set(scene.coordinator->getComponentType<ne::Renderable>());
        sign.set(scene.coordinator->getComponentType<ne::Color>());
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
    }
    PhysicsSystem = scene.coordinator->registerSystem<ne::PhysicsSystem>(scene.coordinator);
    {
        ne::Signature signature;
        signature.set(scene.coordinator->getComponentType<ne::RigidBody>());
        signature.set(scene.coordinator->getComponentType<ne::Transform>());
        signature.set(scene.coordinator->getComponentType<ne::Gravity>());
        scene.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }
    auto entity = scene.coordinator->createEntity();
    scene.coordinator->addComponent(entity, getTransform());
    scene.coordinator->addComponent(entity, getGravity());
    scene.coordinator->addComponent(entity, getRigidBody());
    scene.coordinator->addComponent(entity, getColor());
    scene.coordinator->addComponent(entity, getSkin());
    return (scene);
}