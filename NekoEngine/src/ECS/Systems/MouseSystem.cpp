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
#include "../Client/include/ClientGame.hpp"
void ne::MouseSystem::update()
{
    for (auto& entity: m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& skin = coordinator->getComponent<ne::Skin>(entity);
        auto& but = coordinator->getComponent<ne::But>(entity);
        ne::Math::Vector2i mouse = ne::Graphics::Window::getMousePosition();
        if (skin.sprite.getTextureRect().left != skin.texture.getSize().x) {
                sf::IntRect rect;
                rect.left = skin.texture.getSize().x / 2;
                skin.sprite.setTextureRect(sf::IntRect(rect.left, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
        }
        if (mouse.x >= (transform.position.x * ne::Graphics::Window::getScale().x )&& mouse.x <= ((transform.position.x + skin.texture.getSize().x * skin.sprite.getScale().x / 2) * ne::Graphics::Window::getScale().x) && mouse.y >= (transform.position.y * ne::Graphics::Window::getScale().y) && mouse.y <= (transform.position.y + skin.texture.getSize().y * skin.sprite.getScale().y) * ne::Graphics::Window::getScale().y && transform.position.x != 0) {
            if (skin.sprite.getTextureRect().left > 0)
                skin.sprite.setTextureRect(sf::IntRect(skin.sprite.getTextureRect().left - skin.texture.getSize().x / 2, skin.sprite.getTextureRect().top, skin.sprite.getTextureRect().width, skin.sprite.getTextureRect().height));
            if (ne::Graphics::Window::isClicked()) {
                if (but.name == "Quit") {
                    //should close
                    ne::Graphics::Window::mustClose();
                }
                if (but.name == "Setting")
                    //should change scene to setting scene
                    ne::Graphics::Window::setScene(1);
                if (but.name == "Start")
                    //should change scene to lobby scene
                    ne::Graphics::Window::setScene(2);
                if (but.name == "Return")
                    //should return to the main menu scene
                    ne::Graphics::Window::setScene(0);
            }                
        }
    }
}