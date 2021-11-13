/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicPlane
*/

#include "BasicPlane.hpp"

ne::BasicPlane::BasicPlane()
{
    getHitPoint().setHp(1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 800);
    std::random_device rd3;
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> distribY(0, 600);
    trans.position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    trans.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    trans.scale = ne::Math::Vector3f{4.f, 4.f, 0.f};
    grav.force = ne::Math::Vector3f{0.f, 2.f, 0.f};
    rigid.acceleration = ne::Math::Vector3f{-140.f, 0.f, 0.f};
    rigid.velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    temp = { 255, 255, 255, 255 };
    skin.texture->loadFromFile("Ennemies/Assets/TouhouBasicMob.png", sf::IntRect(0, 0, 32, 32));
        //throw std::runtime_error("Error loading Ennemies/Assets/TouhouBasicMob.png file");
    //skin.sprite.setTexture(*(skin).texture);
}

ne::BasicPlane::~BasicPlane()
{
}