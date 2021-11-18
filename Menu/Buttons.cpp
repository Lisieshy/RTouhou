/*
** EPITECH PROJECT, 2021
** Buttons.cpp
** File description:
** Buttons.cpp
*/

#include "Buttons.hpp"

ne::Buttons::Buttons(const std::string &_name, const std::string &text, ne::Math::Vector2u pos, ne::Math::Vector4u rect)
{
    _rect = rect;
    name = _name;
    _text = text;
    if (!skin.texture.loadFromFile(text))
        throw std::runtime_error("Error, couldn't load " + text);
    skin.sprite.setTexture(skin.texture);
    skin.sprite.setTextureRect(sf::IntRect(rect.x, rect.y, rect.z, rect.w));
    skin.sprite.setScale({1.5, 1.5});
    but.name = _name;
    _pos.x = pos.x - skin.texture.getSize().x / 2;
    _pos.y = pos.y;
    transf.position = ne::Math::Vector3f{static_cast<float>(pos.x) - skin.texture.getSize().x / 2, static_cast<float>(pos.y), 0.f};
    transf.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.scale = ne::Math::Vector3f{static_cast<float>(ne::Graphics::Window::getWindow().x), static_cast<float>(ne::Graphics::Window::getWindow().y), 0.f};
    std::cout << skin.sprite.getTextureRect().width << std::endl;
    // sf::Text _text;
    // sf::Font font;
    // font.loadFromFile("resources/arial.ttf");
    // _text.setString(text);
    // _text.setFillColor(sf::Color(255,255,255,255));
}

ne::Buttons::~Buttons()
{
}

void ne::Buttons::setState(bool state)
{
    std::cout << _text << std::endl;
    if (state == true)
        skin.sprite.setTextureRect(sf::IntRect(_rect.x - 72, _rect.y, _rect.z, _rect.w));
    else    
        skin.sprite.setTextureRect(sf::IntRect(_rect.x, _rect.y, _rect.z, _rect.w));
}



ne::Transform ne::Buttons::getTransform()
{
    transf.position.x *= ne::Graphics::Window::getScale().x;
    transf.position.y *= ne::Graphics::Window::getScale().y;
    return (transf);
}

ne::Gravity ne::Buttons::getGravity()
{
    ne::Gravity grav;
    return (grav);
}

ne::RigidBody ne::Buttons::getRigidBody()
{
    ne::RigidBody rigid;
    return (rigid);
}

ne::Color ne::Buttons::getColor()
{
    ne::Color temp;
    temp = {0, 0, 0, 0};
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

ne::But ne::Buttons::getBut()
{
    return (but);
}