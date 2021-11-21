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
        bool isClicked = false;
        int nb = 0;
    };
}

static std::unique_ptr<ne::Graphics::Window::WImpl> impl;

int ne::Graphics::Window::getScene()
{
    return (impl->nb);
}

void ne::Graphics::Window::setScene(int nb)
{
    impl->nb = nb;
}

void ne::Graphics::Window::open() {
    impl = std::make_unique<ne::Graphics::Window::WImpl>();
    sf::err().rdbuf(nullptr); // Disabling SFML Error from showing.
    impl->i_window.create(sf::VideoMode(800, 600), "NekoEngine");
    impl->i_window.setVerticalSyncEnabled(true);
    impl->shouldClose = false;
}

ne::Math::Vector2f ne::Graphics::Window::getScale()
{
    ne::Math::Vector2f _scale;
    _scale.x = (impl->i_window.getSize().x / 800.0f);
    _scale.y = (impl->i_window.getSize().y / 600.0f);
    return (_scale);
}

ne::Math::Vector2u ne::Graphics::Window::getWindow()
{
    ne::Math::Vector2u vect;
    vect.x = impl->i_window.getSize().x;
    vect.y = impl->i_window.getSize().y;
    return(vect);
}

void ne::Graphics::Window::close() {
    if (impl)
        impl->i_window.close();
    impl.reset();
}

void ne::Graphics::Window::mustClose() {
    impl->shouldClose = true;
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
            if (event.key.code == sf::Keyboard::Key::P) {
                nl::nyalog(nl::LogLevel::Info, "Pressed P!");
                client->PingServer();
            }   
            if (event.key.code == sf::Keyboard::Key::M) {
                nl::nyalog(nl::LogLevel::Info, "Pressed M!");
                client->MessageAll();
            }
        }
        impl->isClicked = false;
        if (event.mouseButton.button == sf::Mouse::Left) {
            impl->isClicked = true;
        }
    }
}

void ne::Graphics::Window::display() {
    impl->i_window.display();
}

bool ne::Graphics::Window::isClicked() {
    return (impl->isClicked);
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

void ne::Graphics::Window::draw(ne::Textinfo& text)
{
    text._text.setFont(text.font);
    impl->i_window.draw(text._text);
}

ne::Math::Vector2i ne::Graphics::Window::getMousePosition()
{
    ne::Math::Vector2i mouse;
    mouse.x = sf::Mouse::getPosition(impl->i_window).x;
    mouse.y = sf::Mouse::getPosition(impl->i_window).y;
    return (mouse);
}