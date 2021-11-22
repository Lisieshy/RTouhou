/*
** EPITECH PROJECT, 2021
** Background.cpp
** File description:
** Background.cpp
*/

#include "Background.hpp"

ne::Background::Background()
{
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/menu.png"));
    skin.sprite.setScale({1.5, 1.5});
}

ne::Background::~Background()
{
}

ne::Skin& ne::Background::getSkin()
{
    return(skin);
}