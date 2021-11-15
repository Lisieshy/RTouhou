/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bullets
*/

#include "Bullets.hpp"

ne::Bullets::Bullets()
{
}

ne::Bullets::~Bullets()
{
}

ne::Transform ne::Bullets::getTransform()
{
    return (transform);
}

ne::Gravity ne::Bullets::getGravity()
{
    return (gravity);
}

ne::RigidBody ne::Bullets::getRigidBody()
{
    return (rigidbody);
}

ne::Skin ne::Bullets::getSkin()
{
    return (skin);
}