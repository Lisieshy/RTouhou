/*
** EPITECH PROJECT, 2021
** Buttons.cpp
** File description:
** Buttons.cpp
*/

#include "Buttons.hpp"

ne::Buttons::Buttons(const std::string &_name, const std::string &text, ne::Math::Vector2u pos)
{
    name = _name;
    if (!skin.texture.loadFromFile(text))
        throw std::runtime_error("Error, couldn't load " + text);
    transf.position = ne::Math::Vector3f{static_cast<float>(pos.x) - skin.texture.getSize().x / 2, static_cast<float>(pos.y), 0.f};
    transf.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.scale = ne::Math::Vector3f{0.f, 0.f, 0.f};
    skin.sprite.setTexture(skin.texture);
    skin.sprite.setScale({1.5, 1.5});
    temp = {0, 0, 0, 0};
    std::cout << transf.position.x << std::endl;
    std::cout << transf.position.y << std::endl;
    // sf::Text _text;
    // sf::Font font;
    // font.loadFromFile("resources/arial.ttf");
    // _text.setString(text);
    // _text.setFillColor(sf::Color(255,255,255,255));
}

ne::Buttons::~Buttons()
{
}


ne::Transform ne::Buttons::getTransform()
{
    return (transf);
}

ne::Gravity ne::Buttons::getGravity()
{
    return (grav);
}

ne::RigidBody ne::Buttons::getRigidBody()
{
    return (rigid);
}

ne::Color ne::Buttons::getColor()
{
    return (temp);
}

ne::Skin ne::Buttons::getSkin()
{
    return (skin);
}

ne::Scene ne::Buttons::getScene()
{
    return (scene);
}

std::string ne::Buttons::getName()
{
    return (name);
}