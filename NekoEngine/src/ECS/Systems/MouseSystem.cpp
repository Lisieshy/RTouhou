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
        std::cout << skin.sprite.getTextureRect().left << std::endl;
        if (skin.sprite.getTextureRect().left != 72) {
                sf::IntRect rect;
                rect.left = 72;
                skin.sprite.setTextureRect(sf::IntRect(rect.left, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
        }
        if (mouse.x >= transform.position.x && mouse.x <= transform.position.x + 72 && mouse.y >= transform.position.y && mouse.y <= transform.position.y + 12 && transform.position.x != 0) {
            if (skin.sprite.getTextureRect().left > 0)
                skin.sprite.setTextureRect(sf::IntRect(skin.sprite.getTextureRect().left - 72, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
            if (ne::Graphics::Window::isClicked()) {
                if (skin.name == "Quit")
                    //should close
                    std::cout << "Quit" << std::endl;
                if (skin.name == "Setting")
                    //should change scene to setting scene
                    std::cout << "Setting" << std::endl;
                if (skin.name == "Start")
                    //should change scene to lobby scene
                    std::cout << "Start" << std::endl;
            }
                
            std::cout << "button ???" << std::endl;
            //std::cout << skin.sprite.getTextureRect().width << std::endl;
        }
            std::cout << std::endl;
    }
}