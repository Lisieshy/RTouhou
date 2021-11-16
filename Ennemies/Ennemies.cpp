/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Ennemies
*/

#include "Ennemies.hpp"

ne::Ennemies::Ennemies()
{
}

ne::Ennemies::~Ennemies()
{
}

void ne::Ennemies::setPattern(std::function<ne::Math::Vector3f()> func)
{
    pat.patternFunc = func;
}

ne::Patterns& ne::Ennemies::getPattern()
{
    return (pat);
}

ne::HitPoint ne::Ennemies::getHitPoint()
{
    return (hp);
}

ne::Transform ne::Ennemies::getTransform()
{
    return (trans);
}

ne::Gravity ne::Ennemies::getGravity()
{
    return (grav);
}

ne::RigidBody ne::Ennemies::getRigidBody()
{
    return (rigid);
}

ne::Color ne::Ennemies::getColor()
{
    return (temp);
}

ne::Skin ne::Ennemies::getSkin()
{
    return (skin);
}