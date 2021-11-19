/*
** EPITECH PROJECT, 2021
** Buttons.cpp
** File description:
** Buttons.cpp
*/

#include "Buttons.hpp"

ne::Buttons::Buttons(const std::string &_name, const std::string &path, ne::Math::Vector2u pos)
{
    skin.texture = ne::GlobalTexture::Instance().GetData(path);
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData(path));
    skin.sprite.setTextureRect(sf::IntRect(0, 0, skin.texture.getSize().x / 2, skin.texture.getSize().y));
    skin.sprite.setScale({1.5, 1.5});
    but.name = _name;
    transf.position = ne::Math::Vector3f{static_cast<float>(pos.x) - skin.texture.getSize().x / 2, static_cast<float>(pos.y), 0.f};
    transf.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.scale = ne::Math::Vector3f{static_cast<float>(ne::Graphics::Window::getWindow().x), static_cast<float>(ne::Graphics::Window::getWindow().y), 0.f};
}

ne::Buttons::~Buttons()
{
}

ne::Transform ne::Buttons::getTransform()
{
    return (transf);
}

ne::Skin ne::Buttons::getSkin()
{
    return (skin);
}

ne::But ne::Buttons::getBut()
{
    return (but);
}