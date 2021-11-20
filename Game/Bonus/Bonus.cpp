/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bonus
*/

#include "Bonus.hpp"

ne::Bonus::Bonus()
{
}

ne::Bonus::~Bonus()
{
}

ne::Transform& ne::Bonus::getTransform()
{
    return (transform);
}

ne::Skin& ne::Bonus::getSkin()
{
    return (skin);
}

ne::Patterns& ne::Bonus::getPattern()
{
    return (pat);
}

ne::EntityType::Type& ne::Bonus::getType()
{
    return (Type);
}

void ne::Bonus::setTransform(ne::Transform trans)
{
    transform = trans;
}

void ne::Bonus::setSkin(ne::Skin sk)
{
    skin = sk;
}

void ne::Bonus::setPattern(std::function<ne::Math::Vector3f()> func)
{
    pat.patternFunc = func;
}

void ne::Bonus::setType(ne::EntityType::Type newType)
{
    Type = newType;
}