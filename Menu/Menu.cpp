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

ne::Skin ne::Menu::getSkin()
{
    ne::Skin skin;
    skin.sprite.setTexture(ne::GlobalTexture::Instance().GetData("resources/menu.png"));
    skin.sprite.setScale({1.5, 1.5});
    return (skin);
}

ne::Transform ne::Menu::getTransform()
{
    ne::Transform trans;
    return(trans);
}

ne::Scene ne::Menu::getScene()
{
    scene.coordinator->registerComponent<ne::Transform, ne::Renderable, ne::Skin, ne::But>();
    Rendering = scene.coordinator->registerSystem<ne::RenderSystem>(scene.coordinator);
    {
        ne::Signature sign;
        sign.set(scene.coordinator->getComponentType<ne::Transform>());
        sign.set(scene.coordinator->getComponentType<ne::Renderable>());
        sign.set(scene.coordinator->getComponentType<ne::Skin>());
    }
    MouseSys = scene.coordinator->registerSystem<ne::MouseSystem>(scene.coordinator);
    {
        ne::Signature signature;
        signature.set(scene.coordinator->getComponentType<ne::But>());
        signature.set(scene.coordinator->getComponentType<ne::Transform>());
        scene.coordinator->setSystemSignature<ne::MouseSystem>(signature);
    }
    std::vector<ne::Buttons> usine;
    usine.push_back(ne::Buttons("Start", "resources/button_start.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4)));
    usine.push_back(ne::Buttons("Setting", "resources/button_settings.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 2)));
    usine.push_back(ne::Buttons("Quit", "resources/button_quit.png",
    ne::Math::Vector2u(ne::Graphics::Window::getWindow().x / 2, ne::Graphics::Window::getWindow().y / 4 * 3)));
    size_t i = 0;
    auto gorboulut = scene.coordinator->createEntity();
    scene.coordinator->addComponent(gorboulut, getTransform());
    scene.coordinator->addComponent(gorboulut, getSkin());
    for (auto entity: entities) {
        entity = scene.coordinator->createEntity();
        scene.coordinator->addComponent(entity, usine.at(i).getTransform());
        scene.coordinator->addComponent(entity, usine.at(i).getSkin());
        scene.coordinator->addComponent(entity, usine.at(i).getBut());
        i++;
        if (usine.size() == i)
            break;
    }
    return (scene);
}