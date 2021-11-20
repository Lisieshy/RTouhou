/*
** EPITECH PROJECT, 2021
** Menu.cpp
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "Buttons.hpp"
#include "Background.hpp"
#include "Parallax.hpp"
ne::Menu::Menu(std::vector<ne::EntityID> entities)
{
    ne::Scene scene;
    scene.coordinator->registerComponent<ne::Transform, ne::Renderable, ne::Skin, ne::But, ne::GorbBackground, ne::ParallaxSystem>();
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
    ParaSys = scene.coordinator->registerSystem<ne::ParallaxSystem>(scene.coordinator);
    {
        ne::Signature signature;
        signature.set(scene.coordinator->getComponentType<ne::Skin>());
        signature.set(scene.coordinator->getComponentType<ne::GorbBackground>());
        signature.set(scene.coordinator->getComponentType<ne::Transform>());
        signature.set(scene.coordinator->getComponentType<ne::ParallaxSystem>());
        scene.coordinator->setSystemSignature<ne::ParallaxSystem>(signature);
    }
    ne::Background bg;
    ne::Parallax par;
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
    auto parallax = scene.coordinator->createEntity();
    scene.coordinator->addComponent(parallax, par.getSkin());
    scene.coordinator->addComponent(parallax, par.getTransform());
    scene.coordinator->addComponent(parallax, ne::ParallaxSystem{});
    scene.coordinator->addComponent(parallax, ne::GorbBackground{});
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