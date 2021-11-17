/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** DarkBlueFerry
*/

#include "DarkBlueFerry.hpp"

ne::DarkBlueFerry::DarkBlueFerry()
{
    std::random_device rd;
    std::random_device rd3;
    std::mt19937 gen(rd());
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> distrib(0, 800);
    std::uniform_int_distribution<> distribY(0, 600);

    ne::Transform transform;
    transform.position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    transform.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transform.scale = ne::Math::Vector3f{32.f, 32.f, 0.f};
    setTransform(transform);

    ne::Gravity grav;
    grav.force = ne::Math::Vector3f{0.f, 8.f, 0.f};
    setGravity(grav);

    ne::RigidBody rigid;
    rigid.acceleration = ne::Math::Vector3f{-140.f, 0.f, 0.f};
    rigid.velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    setRigitBody(rigid);

    ne::Color temp;
    temp = { 255, 255, 255, 255 };
    setColor(temp);

    ne::Skin skin;
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/Ennemies/TouhouBasicMob.png"));
    skin.sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    setSkin(skin);

    ne::Alien alienShot;
    alienShot.TimeToShoot = 2.f;
    alienShot.BasicTime = 2.f;
    setAlien(alienShot);
}

ne::DarkBlueFerry::~DarkBlueFerry()
{
}
