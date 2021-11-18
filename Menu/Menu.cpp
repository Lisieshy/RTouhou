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

}

ne::Menu::~Menu()
{
}

ne::Transform ne::Menu::getTransform()
{
    ne::Transform transf;
    return (transf);
}

ne::Gravity ne::Menu::getGravity()
{
    ne::Gravity grav;
    return (grav);
}

ne::RigidBody ne::Menu::getRigidBody()
{
    ne::RigidBody rigid;
    return (rigid);
}

ne::Color ne::Menu::getColor()
{
    ne::Color temp;
    temp = {0, 0, 0, 0};
    return (temp);
}

ne::Skin ne::Menu::getSkin()
{
    ne::Skin skin;
    if (!skin.texture.loadFromFile("resources/menu.png"))
        throw std::runtime_error("Error, couldn't load resources/bg.jpg");
    skin.sprite.setTexture(skin.texture);
    skin.sprite.setScale({1.5, 1.5});
    return (skin);
}

ne::Scene ne::Menu::getScene()
{
    scene.coordinator->registerComponent<ne::Transform, ne::Renderable, ne::Color, ne::Skin, ne::But>();
    Rendering = scene.coordinator->registerSystem<ne::RenderSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Transform>());
        sign.set(scene.coordinator->getComponentType<ne::Renderable>());
        sign.set(scene.coordinator->getComponentType<ne::Color>());
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
    }
    MouseSys = scene.coordinator->registerSystem<ne::MouseSystem>(scene.coordinator);
    {
        ne::Signature signature;
        signature.set(scene.coordinator->getComponentType<ne::But>());
        signature.set(scene.coordinator->getComponentType<ne::Transform>());
    }
    std::vector<ne::Buttons> usine;
    usine.push_back(ne::Buttons("Start", "resources/button_start_test.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4), ne::Math::Vector4u(0, 0, 72, 12)));
    usine.push_back(ne::Buttons("Setting", "resources/button_settings_test.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 2), ne::Math::Vector4u(0,0,72,12)));
    usine.push_back(ne::Buttons("Quit", "resources/button_quit_test.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4 * 3), ne::Math::Vector4u(72,0,72,12)));
    size_t i = 0;
    auto gorboulut = scene.coordinator->createEntity();
    scene.coordinator->addComponent(gorboulut, getTransform());
    scene.coordinator->addComponent(gorboulut, getColor());
    scene.coordinator->addComponent(gorboulut, getSkin());
    for (auto entity: entities) {
        entity = scene.coordinator->createEntity();
        scene.coordinator->addComponent(entity, usine.at(i).getTransform());
        scene.coordinator->addComponent(entity, usine.at(i).getColor());
        scene.coordinator->addComponent(entity, usine.at(i).getSkin());
        scene.coordinator->addComponent(entity, ne::But());

        i++;
        if (usine.size() == i)
            break;
    }
    return (scene);
}