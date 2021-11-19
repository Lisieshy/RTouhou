/*
** EPITECH PROJECT, 2021
** Text.cpp
** File description:
** Text.cpp
*/

#include "Text.hpp"

ne::Text::Text(const std::string &name, const std::string &text, ne::Math::Vector2u pos)
{
    _textinfo.font.loadFromFile("resources/arial.ttf");
    _textinfo._text.setString(text);
    _textinfo._text.setFont(_textinfo.font);
    _textinfo._text.setColor(sf::Color::Green);
    transf.position = ne::Math::Vector3f{static_cast<float>(pos.x) - _textinfo._text.getGlobalBounds().left / 2, static_cast<float>(pos.y), 0.f};
}

ne::Text::~Text()
{
}

ne::Textinfo& ne::Text::getTextInfo()
{
    return (_textinfo);
}

ne::Transform& ne::Text::getTransform()
{
    return (transf);
}