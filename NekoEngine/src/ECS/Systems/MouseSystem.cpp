/*
** EPITECH PROJECT, 2021
** MouseSystem.cpp
** File description:
** MouseSystem.cpp
*/



#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/MouseSystem.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include "NekoEngine/Graphics/Window.hpp"

void ne::MouseSystem::update()
{
    for (auto& entity: m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& skin = coordinator->getComponent<ne::Skin>(entity);
        ne::Math::Vector2i mouse = ne::Graphics::Window::getMousePosition();
        std::cout << "trans = " << transform.position.x << std::endl;
        std::cout << "mouse = " << mouse.x << std::endl;
        if (mouse.x >= transform.position.x && mouse.x <= transform.position.x + 72 && mouse.y >= transform.position.y && mouse.y <= transform.position.y + 12) {
            std::cout << "button ???" << std::endl;
            //std::cout << skin.sprite.getTextureRect().width << std::endl;
        }std::cout << std::endl;
    }
}