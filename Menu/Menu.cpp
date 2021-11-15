/*
** EPITECH PROJECT, 2021
** Menu.cpp
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "Buttons.hpp"

ne::Menu::Menu(std::vector<ne::EntityID> entity)
{
    entities = entity;
    if (!skin.texture.loadFromFile("resources/menu.png"))
        throw std::runtime_error("Error, couldn't load resources/bg.jpg");
    transf.position = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.rotation = ne::Math::Vector3f{0.f, 0.f, 0.f};
    transf.scale = ne::Math::Vector3f{0.f, 0.f, 0.f};
    skin.sprite.setTexture(skin.texture);
    skin.sprite.setScale({1.5, 1.5});
    temp = {0, 0, 0, 0};
}

ne::Menu::~Menu()
{
}

ne::Transform ne::Menu::getTransform()
{
    return (transf);
}

ne::Gravity ne::Menu::getGravity()
{
    return (grav);
}

ne::RigidBody ne::Menu::getRigidBody()
{
    return (rigid);
}

ne::Color ne::Menu::getColor()
{
    return (temp);
}

ne::Skin ne::Menu::getSkin()
{
    return (skin);
}

ne::Scene ne::Menu::getScene()
{
    scene.coordinator->registerComponent<ne::Transform, ne::Renderable, ne::Color, ne::Skin>();
    Rendering = scene.coordinator->registerSystem<ne::RenderSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Transform>());
        sign.set(scene.coordinator->getComponentType<ne::Renderable>());
        sign.set(scene.coordinator->getComponentType<ne::Color>());
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
    }
    std::vector<ne::Buttons> usine;
    usine.push_back(ne::Buttons("Start", "resources/button_start.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4)));
    usine.push_back(ne::Buttons("Settings", "resources/button_settings.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 2)));
    usine.push_back(ne::Buttons("Quit", "resources/button_quit.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4 * 3)));
    size_t i = 0;
    auto gorboulut = scene.coordinator->createEntity();
    scene.coordinator->addComponent(gorboulut, getTransform());
    scene.coordinator->addComponent(gorboulut, getColor());
    scene.coordinator->addComponent(gorboulut, getSkin());
    for (auto entity: entities) {
        entity = scene.coordinator->createEntity();
        std::cout << usine.at(i).getName() << std::endl;
        scene.coordinator->addComponent(entity, usine.at(i).getTransform());
        scene.coordinator->addComponent(entity, usine.at(i).getColor());
        scene.coordinator->addComponent(entity, usine.at(i).getSkin());
        i++;
        if (usine.size() == i)
            break;
    }
    return (scene);
}