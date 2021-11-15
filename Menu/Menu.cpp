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

