/*
** EPITECH PROJECT, 2021
** ParallaxSystem.cpp
** File description:
** ParallaxSystem.cpp
*/

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/ParallaxSystem.hpp"
#include "NekoEngine/ECS/Components/Skin.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/Graphics/Window.hpp"
#include "NekoEngine/ECS/Systems/BackgroundSystem.hpp"

void ne::ParallaxSystem::update(float dt)
{
    for (auto& entity: m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& spr = coordinator->getComponent<ne::Skin>(entity);
        transform.position.y += 10 * dt;
        if (transform.position.y > ne::Graphics::Window::getWindow().y + 200)
            transform.position.y = -400;
        ne::Graphics::Window::draw(spr, transform);
    }
}