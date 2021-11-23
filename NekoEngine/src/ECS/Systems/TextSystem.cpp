/*
** EPITECH PROJECT, 2021
** TextSystem.cpp
** File description:
** TextSystem.cpp
*/

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/TextSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/Graphics/Window.hpp"

void ne::TextSystem::update()
{
    for (auto& entity : m_entities) {
        auto& text = coordinator->getComponent<ne::Textinfo>(entity);
        ne::Graphics::Window::draw(text);
    }
}