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

ne::Transform ne::Ennemies::getTransform()
{
    return (transform);
}

ne::Gravity ne::Ennemies::getGravity()
{
    return (gravity);
}

ne::RigidBody ne::Ennemies::getRigidBody()
{
    return (rigidbody);
}

ne::Color ne::Ennemies::getColor()
{
    return (color);
}

ne::Skin ne::Ennemies::getSkin()
{
    return (skin);
}

ne::Alien ne::Ennemies::getAlien()
{
    return (alien);
}

void ne::Ennemies::setRigitBody(ne::RigidBody rigid)
{
    rigidbody = rigid;
}

void ne::Ennemies::setTransform(ne::Transform trans)
{
    transform = trans;
}

void ne::Ennemies::setGravity(ne::Gravity grav)
{
    gravity = grav;
}

void ne::Ennemies::setColor(ne::Color col)
{
    color = col;
}

void ne::Ennemies::setSkin(ne::Skin sk)
{
    skin = sk;
}

void ne::Ennemies::setAlien(ne::Alien ali)
{
    alien = ali;
}