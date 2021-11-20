/*
** EPITECH PROJECT, 2021
** Menu.cpp
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "Buttons.hpp"
#include "Background.hpp"

ne::Menu::Menu(std::vector<ne::EntityID> entities)
{
    ne::Scene scene;
    scene.coordinator->registerComponent<ne::Transform, ne::Renderable, ne::Skin, ne::But, ne::GorbBackground>();
    Rendering = scene.coordinator->registerSystem<ne::RenderSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Transform>());
        sign.set(scene.coordinator->getComponentType<ne::Renderable>());
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
        scene.coordinator->setSystemSignature<ne::RenderSystem>(sign);
    }
    RenderBackground = scene.coordinator->registerSystem<ne::BackgroundSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
        sign.set(scene.coordinator->getComponentType<ne::GorbBackground>());
        scene.coordinator->setSystemSignature<ne::BackgroundSystem>(sign); 
    }
    MouseSys = scene.coordinator->registerSystem<ne::MouseSystem>(scene.coordinator);
    {
        ne::Signature signature;
        signature.set(scene.coordinator->getComponentType<ne::But>());
        signature.set(scene.coordinator->getComponentType<ne::Transform>());
        scene.coordinator->setSystemSignature<ne::MouseSystem>(signature);
    }
    ne::Background bg;
    std::vector<ne::Buttons> usine;
    usine.push_back(ne::Buttons("Start", "resources/button_start.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4)));
    usine.push_back(ne::Buttons("Setting", "resources/button_settings.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 2)));
    usine.push_back(ne::Buttons("Quit", "resources/button_quit.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4 * 3)));
    size_t i = 0;
    auto gorboulut = scene.coordinator->createEntity();
    scene.coordinator->addComponent(gorboulut, bg.getSkin());
    scene.coordinator->addComponent(gorboulut, ne::GorbBackground{});

    for (auto entity: entities) {
        entity = scene.coordinator->createEntity();
        scene.coordinator->addComponent(entity, usine.at(i).getTransform());
        scene.coordinator->addComponent(entity, usine.at(i).getSkin());
        scene.coordinator->addComponent(entity, usine.at(i).getBut());
        scene.coordinator->addComponent(entity, ne::Renderable{});
        i++;
        if (usine.size() == i)
            break;
    }
}

ne::Menu::~Menu()
{
}