/*
** EPITECH PROJECT, 2021
** BackgroundSystem.cpp
** File description:
** BackgroundSystem.cpp
*/

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/BackgroundSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/ECS/Components/Skin.hpp"
#include "NekoEngine/Graphics/Window.hpp"

void ne::BackgroundSystem::update()
{
    for (auto& entity: m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& skin = coordinator->getComponent<ne::Skin>(entity);
        ne::Graphics::Window::draw(skin, transform);
    }
}