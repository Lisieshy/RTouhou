/*
** EPITECH PROJECT, 2021
** Parallax.cpp
** File description:
** Parallax.cpp
*/

#include "Parallax.hpp"

ne::Parallax::Parallax(ne::Math::Vector3f pos, std::string path)
{
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData(path));
    skin.sprite.setScale({1.5, 1.5});
    transf.position = pos;
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