/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** WavesClientSystem
*/

#include "../include/WavesClientSystem.hpp"

void ne::WavesClientSystem::init()
{
    txtinfo.font = ne::GlobalSound::Instance().GetData("resources/arial.ttf");
    txtinfo._text.setString("Wave : 1");
    txtinfo._text.setFont(txtinfo.font);

    ne::Transform transform;    
    transform.position = ne::Math::Vector3f{30.f, 30.f, 0.f},
    transform.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transform.scale = ne::Math::Vector3f{32.f, 32.f, 0.f};
    txtinfo._text.setPosition({ transform.position.x, transform.position.y });
}

void ne::WavesClientSystem::update(float dt)
{
    Time -= dt;
    if (Time <= 0) {
        wave++;
        txtinfo._text.setString("Wave : " + std::to_string(wave));
        Time = 15.0f;
    }
    ne::Graphics::Window::draw(txtinfo);
}