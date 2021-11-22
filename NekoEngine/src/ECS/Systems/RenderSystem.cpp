/*
** EPITECH PROJECT, 2021
** TimerSystem
** File description:
** TimerSystem
*/

/**
 * @file        RenderSystem.cpp
 * @brief       Render System class implementation
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/RenderSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/ECS/Components/Color.hpp"
#include "NekoEngine/ECS/Components/Skin.hpp"
#include "NekoEngine/Graphics/Window.hpp"

void ne::RenderSystem::update()
{
    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& color = coordinator->getComponent<ne::Color>(entity);
        auto& spr = coordinator->getComponent<ne::Skin>(entity);
        ne::Graphics::Window::drawRectangle(transform, color);
        ne::Graphics::Window::draw(spr, transform);
    }
    ne::Graphics::Window::display();
}