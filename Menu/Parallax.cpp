/*
** EPITECH PROJECT, 2021
** Parallax.cpp
** File description:
** Parallax.cpp
*/

#include "Parallax.hpp"

ne::Parallax::Parallax()
{
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/menu.png"));
    skin.sprite.setScale({1.5, 1.5});
}

ne::Parallax::~Parallax()
{
}

ne::Transform& ne::Parallax::getTransform()
{
    return (transf);
}

ne::Skin& ne::Parallax::getSkin()
{
    return (skin);
}