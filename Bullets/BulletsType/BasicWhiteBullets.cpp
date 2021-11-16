/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicWhiteBullets
*/

#include "BasicWhiteBullets.hpp"

ne::BasicWhiteBullets::BasicWhiteBullets()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 800);
    std::random_device rd3;
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> distribY(0, 600);
    transform.position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    transform.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transform.scale = ne::Math::Vector3f{4.f, 4.f, 0.f};
    gravity.force = ne::Math::Vector3f{0.f, 20.f, 0.f};
    rigidbody.acceleration = ne::Math::Vector3f{0.f, 0.f, 0.f};
    rigidbody.velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    if (!skin.texture.loadFromFile("resources/Bullets/bullets.png", sf::IntRect(7, 71, 12, 16)))
        throw std::runtime_error("Error loading resources/Bullets/bullets.png file");
    skin.sprite.setTexture(skin.texture);
}

ne::BasicWhiteBullets::~BasicWhiteBullets()
{
}
