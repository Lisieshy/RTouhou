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

ne::Transform ne::Background::getTransform()
{
    ne::Transform transf;
    return (transf);
}

ne::Skin ne::Background::getSkin()
{
    return(skin);
}

ne::GorbBackground ne::Background::getGorb()
{
    return (gorb);
}