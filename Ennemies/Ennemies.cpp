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