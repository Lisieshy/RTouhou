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

#include <memory>
#include "NekoEngine/Graphics/Window.hpp"
#include <SFML/Graphics.hpp>

namespace ne::Graphics::Window {
    struct WImpl {
        sf::RenderWindow i_window;
    };
}

static std::unique_ptr<ne::Graphics::Window::WImpl> impl;

void ne::Graphics::Window::open() {
    impl = std::make_unique<ne::Graphics::Window::WImpl>();
    impl->i_window.create(sf::VideoMode(800, 600), "NekoEngine");
    impl->i_window.setVerticalSyncEnabled(true);
}

void ne::Graphics::Window::close() {
    impl->i_window.close();
    impl.reset();
}

bool ne::Graphics::Window::isOpen() {
    return impl->i_window.isOpen();
}

void ne::Graphics::Window::pollEvent() {
    for (auto event = sf::Event{}; impl->i_window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            close();
        }
    }
}

void ne::Graphics::Window::display() {
    impl->i_window.display();
}

void ne::Graphics::Window::clear(ne::Color Color) {
    impl->i_window.clear(sf::Color(
        Color.r,
        Color.g,
        Color.b,
        Color.a
    ));
}

void ne::Graphics::Window::drawRectangle(ne::Transform& transform, ne::Color& color) {
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

    impl->i_window.draw(pixel);
}