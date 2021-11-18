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
        auto& but = coordinator->getComponent<ne::But>(entity);
        ne::Math::Vector2i mouse = ne::Graphics::Window::getMousePosition();
        if (skin.sprite.getTextureRect().left != 72) {
                sf::IntRect rect;
                rect.left = 72;
                skin.sprite.setTextureRect(sf::IntRect(rect.left, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
        }
        if (mouse.x >= transform.position.x && mouse.x <= transform.position.x + skin.texture.getSize().x * skin.sprite.getScale().x / 2 && mouse.y >= transform.position.y && mouse.y <= transform.position.y + skin.texture.getSize().y * skin.sprite.getScale().y && transform.position.x != 0) {
            if (skin.sprite.getTextureRect().left > 0)
                skin.sprite.setTextureRect(sf::IntRect(skin.sprite.getTextureRect().left - 72, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
            if (ne::Graphics::Window::isClicked()) {
                if (but.name == "Quit")
                    //should close
                    std::cout << "Quit" << std::endl;
                if (but.name == "Setting")
                    //should change scene to setting scene
                    std::cout << "Setting" << std::endl;
                if (but.name == "Start")
                    //should change scene to lobby scene
                    std::cout << "Start" << std::endl;
            }                
        }
    }
}