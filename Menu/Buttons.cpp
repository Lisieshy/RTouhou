/*
** EPITECH PROJECT, 2021
** Buttons.cpp
** File description:
** Buttons.cpp
*/

#include "Buttons.hpp"

ne::Buttons::Buttons(const std::string &name, const std::string &text, ne::Math::Vector2u pos)
{
    std::cout << name << std::endl;
    sf::Text _text;
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");
    _text.setString(text);
    _text.setFillColor(sf::Color(255,255,255,255));
    std::cout << pos.x << std::endl;
    std::cout << pos.y << std::endl;
}

ne::Buttons::~Buttons()
{
}
