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
    getTransform().position = ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    getTransform().rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    getTransform().scale = ne::Math::Vector3f{4.f, 4.f, 0.f};
    getGravity().force = ne::Math::Vector3f{0.f, 0.f, 0.f};
    getRigidBody().acceleration = ne::Math::Vector3f{-14.f, 0.f, 0.f};
    getRigidBody().velocity = ne::Math::Vector3f{0.f, 0.f, 0.f};
    getColor() = { 255, 255, 255 };
}

ne::BasicPlane::~BasicPlane()
{
}
