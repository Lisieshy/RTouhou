/*
** EPITECH PROJECT, 2021
** Window
** File description:
** Window
*/

/**
 * @file        Window.cpp
 * @brief       Contains the NekoEngine Window class implementation.
 * @details     This Window class acts as a wrapper of raylib's core module and aim's to simplify a lot of stuff.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        10/2021
 */

#include "NekoEngine/Graphics/Window.hpp"
#include "NekoEngine/ECS/Components/Components.hpp"
#include <SFML/Graphics.hpp>

struct ne::Graphics::Window::WImpl
{
    sf::RenderWindow i_window {
        sf::VideoMode(800, 600),
        "R-Touhou",
        sf::Style::Default
    };
    sf::Event event;
};

auto ne::Graphics::Window::Get() -> Window& {
    static Window s_window;
    return s_window;
}

ne::Graphics::Window::Window() : _wImpl(std::make_unique<ne::Graphics::Window::WImpl>()) {
    _wImpl->i_window.setVerticalSyncEnabled(true);
}

ne::Graphics::Window::~Window() {
    _wImpl->i_window.close();
}

bool ne::Graphics::Window::isOpen() const {
    return _wImpl->i_window.isOpen();
}

void ne::Graphics::Window::pollEvent() const {
    while(_wImpl->i_window.pollEvent(_wImpl->event)) {
        if (_wImpl->event.type == sf::Event::Closed) {
            _wImpl->i_window.close();
        }
    }
}

void ne::Graphics::Window::display() const {
    _wImpl->i_window.display();
}

void ne::Graphics::Window::drawRectangle(ne::Transform& transform, ne::Color& color) const {
    sf::RectangleShape pixel;

    pixel.setPosition(
        transform.position.x,
        transform.position.y
    );

    pixel.setSize(
        sf::Vector2f(
            transform.scale.x,
            transform.scale.y
        )
    );

    pixel.setFillColor(
        sf::Color {
            color.r,
            color.g,
            color.b,
            color.a
        }
    );

    _wImpl->i_window.draw(pixel);
}