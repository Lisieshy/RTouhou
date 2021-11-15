/*
** EPITECH PROJECT, 2021
** Window
** File description:
** Window
*/

/**
 * @file        Window.cpp
 * @brief       Contains the NekoEngine Window class implementation.
 * @details     The "Not a Singleton but actually kinda like one but it's not pattern".
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        10/2021
 */

#include <memory>
#include <NekoEngine/Graphics/Window.hpp>
#include <SFML/Graphics.hpp>
#include <NyaNet/NyaNet.hpp>
#include <include/CustomClient.hpp>

namespace ne::Graphics::Window {
    struct WImpl {
        sf::RenderWindow i_window;
        bool shouldClose = false;
    };
}

static std::unique_ptr<ne::Graphics::Window::WImpl> impl;

void ne::Graphics::Window::open() {
    impl = std::make_unique<ne::Graphics::Window::WImpl>();
    sf::err().rdbuf(nullptr); // Disabling SFML Error from showing.
    impl->i_window.create(sf::VideoMode(800, 600), "NekoEngine");
    impl->i_window.setVerticalSyncEnabled(true);
    impl->shouldClose = false;
}

void ne::Graphics::Window::close() {
    if (impl)
        impl->i_window.close();
    impl.reset();
}

bool ne::Graphics::Window::shouldClose() {
    return impl->shouldClose;
}

bool ne::Graphics::Window::isOpen() {
    return impl && impl->i_window.isOpen();
}

void ne::Graphics::Window::pollEvent(std::shared_ptr<rt::CustomClient> client) {
    for (auto event = sf::Event{}; impl->i_window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            impl->shouldClose = true;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Escape) {
                impl->shouldClose = true;
            }
            if (event.key.code == sf::Keyboard::Key::A) {
                nl::nyalog(nl::LogLevel::Info, "Pressed A!");
                client->PingServer();
            }   
            if (event.key.code == sf::Keyboard::Key::Z) {
                nl::nyalog(nl::LogLevel::Info, "Pressed Z!");
                client->MessageAll();
            }
        }
    }
}

void ne::Graphics::Window::display() {
    impl->i_window.display();
}

void ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char> Color) {
    impl->i_window.clear(sf::Color(
        Color.x,
        Color.y,
        Color.z,
        Color.w
    ));
}

void ne::Graphics::Window::setTitle(std::string& title) {
    impl->i_window.setTitle(title);
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

void ne::Graphics::Window::draw(ne::Skin skin, ne::Transform transform)
{
    skin.sprite.move({transform.position.x, transform.position.y});
    impl->i_window.draw(skin.sprite);
}