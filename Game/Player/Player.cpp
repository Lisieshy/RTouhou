/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz [WSL: Ubuntu-20.04]
** File description:
** Player
*/

#include "Player.hpp"

ne::Player::Player()
{
}

ne::Player::~Player()
{
}

ne::Transform& ne::Player::getTransform()
{
    return (transform);
}

ne::Gravity& ne::Player::getGravity()
{
    return (gravity);
}

ne::Uid& ne::Player::getUid()
{
    return (id);
}

ne::RigidBody& ne::Player::getRigidBody()
{
    return (rigidbody);
}

ne::Color& ne::Player::getColor()
{
    return (color);
}

ne::Skin& ne::Player::getSkin()
{
    return (skin);
}

ne::EntityType::Type& ne::Player::getType()
{
    return (type);
}

rt::Controller& ne::Player::getController()
{
    return (ctr);
}

void ne::Player::setRigitBody(ne::RigidBody rigid)
{
    rigidbody = rigid;
}

void ne::Player::setTransform(ne::Transform trans)
{
    transform = trans;
}

void ne::Player::setGravity(ne::Gravity grav)
{
    gravity = grav;
}

void ne::Player::setColor(ne::Color col)
{
    color = col;
}

void ne::Player::setSkin(ne::Skin sk)
{
    skin = sk;
}

void ne::Player::setController(rt::Controller ali)
{
    alien = ali;
}

void ne::Player::setType(ne::EntityType::Type newType)
{
    type = newType;
}

void ne::Player::setUid(uint32_t uid)
{
    id = uid;
}