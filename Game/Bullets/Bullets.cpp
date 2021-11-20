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

ne::Transform& ne::Bullets::getTransform()
{
    return (transform);
}

ne::Gravity& ne::Bullets::getGravity()
{
    return (gravity);
}

ne::RigidBody& ne::Bullets::getRigidBody()
{
    return (rigidbody);
}

ne::Color& ne::Bullets::getColor()
{
    return (color);
}

ne::Skin& ne::Bullets::getSkin()
{
    return (skin);
}

ne::Patterns& ne::Bullets::getPattern()
{
    return (pat);
}

ne::EntityType::Type& ne::Bullets::getType()
{
    return (Type);
}

void ne::Bullets::setRigitBody(ne::RigidBody rigid)
{
    rigidbody = rigid;
}

void ne::Bullets::setTransform(ne::Transform trans)
{
    transform = trans;
}

void ne::Bullets::setGravity(ne::Gravity grav)
{
    gravity = grav;
}

void ne::Bullets::setColor(ne::Color col)
{
    color = col;
}

void ne::Bullets::setSkin(ne::Skin sk)
{
    skin = sk;
}

void ne::Bullets::setPattern(std::function<ne::Math::Vector3f()> func)
{
    pat.patternFunc = func;
}

void ne::Bullets::setType(ne::EntityType::Type newType)
{
    Type = newType;
}