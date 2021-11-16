/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** DarkBlueFerry
*/

#include "DarkBlueFerry.hpp"

ne::DarkBlueFerry::DarkBlueFerry()
{

}

ne::DarkBlueFerry::~DarkBlueFerry()
{
}

ne::Transform ne::DarkBlueFerry::getTransform()
{
    std::random_device rd;
    std::random_device rd3;
    std::mt19937 gen(rd());
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> distrib(0, 800);
    std::uniform_int_distribution<> distribY(0, 600);

    ne::Transform trans;
    trans.position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    trans.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    trans.scale = ne::Math::Vector3f{32.f, 32.f, 0.f};

    return (trans);
}

ne::Gravity ne::DarkBlueFerry::getGravity()
{
    ne::Gravity grav;

    grav.force = ne::Math::Vector3f{0.f, 0.f, 0.f};
    return (grav);
}

ne::RigidBody ne::DarkBlueFerry::getRigidBody()
{
    ne::RigidBody rigid;

    rigid.acceleration = ne::Math::Vector3f{0.f, 0.f, 0.f};
    rigid.velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    return (rigid);
}

ne::Color ne::DarkBlueFerry::getColor()
{
    ne::Color temp;

    temp = { 255, 255, 255, 255 };
    return (temp);
}

ne::Skin ne::DarkBlueFerry::getSkin()
{
    ne::Skin skin;

    if (!skin.texture.loadFromFile("Game/Ennemies/Assets/TouhouBasicMob.png", sf::IntRect(0, 138, 32, 32)))
        throw std::runtime_error("Error loading Ennemies/Assets/TouhouBasicMob.png file");
    skin.sprite.setTexture(skin.texture);
    return (skin);
}

ne::Alien ne::DarkBlueFerry::getAlien()
{
    ne::Alien alienShot;

    alienShot.TimeToShoot = 2.f;
    alienShot.BasicTime = 2.f;
    return (alienShot);
}