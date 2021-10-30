/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

/**
 * @file        main.cpp
 * @brief       Basic main file to test functionalities.
 * @details     If this one ends up on production then it means we fucked up real hard somewhere. Great.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#include <iostream>
#include <string>
#include "NekoEngine/NekoEngine.hpp"

int main(void)
{
    ne::Scene Scene;

    Scene.coordinator->registerComponent<ne::Transform, ne::Timer>();

    auto TimerSystem = Scene.coordinator->registerSystem<ne::TimerSystem>(Scene.coordinator);
    {
        ne::Signature signature;
        signature.set(Scene.coordinator->getComponentType<ne::Transform>());
        signature.set(Scene.coordinator->getComponentType<ne::Timer>());
        Scene.coordinator->setSystemSignature<ne::TimerSystem>(signature);
    }

    // Scene.coordinator->addComponent(
    //     neCamera,
    //     ne::Camera3D{
    //         camPos,
    //         camTgt,
    //         camUp,
    //         90.0f
    //     }
    // );

    // ne::EntityID Player = Scene.coordinator->createEntity();

    // Scene.coordinator->addComponent(Player, ne::Transform{
    //     ne::Vector3f { -20.0f, 10.0f, 55.0f },
    //     ne::Vector3f { 0.0f, 0.0f, 0.0f },
    //     ne::Vector3f { 1.0f, 1.0f, 1.0f }
    // });
    // Scene.coordinator->addComponent(Player, ne::ModelAnimation{animPath});
    // Scene.coordinator->addComponent(Player, ne::Model{path});
    // Scene.coordinator->addComponent(Player, ne::Texture{texturePath});
    // Scene.coordinator->addComponent(Player, ne::Controllable(ne::Controller::KEYBOARDLEFT));
    // Scene.coordinator->addComponent(Player, ne::RigidBody{ne::Vector3f{ 5, 12, 5 }, true, 2});
    // Scene.coordinator->addComponent(Player, ne::Destructible{3, false});

    // ne::EntityID PlayerTwo = Scene.coordinator->createEntity();

    // Scene.coordinator->addComponent(PlayerTwo, ne::Transform{
    //     ne::Vector3f { 20.0f, 10.0f, -50.0f },
    //     ne::Vector3f { 0.0f, 0.0f, 0.0f },
    //     ne::Vector3f { 1.0f, 1.0f, 1.0f }
    // });
    // Scene.coordinator->addComponent(PlayerTwo, ne::ModelAnimation{animPath});
    // Scene.coordinator->addComponent(PlayerTwo, ne::Model{path});
    // Scene.coordinator->addComponent(PlayerTwo, ne::Texture{texturePath});
    // Scene.coordinator->addComponent(PlayerTwo, ne::Controllable(ne::Controller::KEYBOARDRIGHT));
    // Scene.coordinator->addComponent(PlayerTwo, ne::RigidBody{ne::Vector3f{ 5, 12, 5 }, true, 4});
    // Scene.coordinator->addComponent(PlayerTwo, ne::Destructible{3, false});

    // ne::Vector3f BlockPos = { 0, 0, 0 };
    // ne::Vector3f BlockRot = { 0.0f, 0.0f, 0.0f };
    // ne::Vector3f BlockScl = { 30.0f, 5.0f, 60.0f };

    // ne::EntityID Floor = Scene.coordinator->createEntity();

    // Scene.coordinator->addComponent(Floor, ne::Transform{});
    // Scene.coordinator->addComponent(Floor, ne::Model{blockPath});
    // Scene.coordinator->addComponent(Floor, ne::Texture{redstoneTexturePath});
    // Scene.coordinator->addComponent(Floor, ne::RigidBody{ ne::Vector3f{ 70, 5, 140 }, false, -1});

    // ne::Vector3f WallPos = { 30.0f, 5.0f, 65.0f };
    // ne::Vector3f WallRot = { 0.0f, 0.0f, 0.0f };
    // ne::Vector3f WallScl = { 5.0f, 5.0f, 5.0f };


    // while (ne::Window::Get().isOpen)
    // {
    //     if (ne::Window::Get().shouldClose())
    //         return;
    //     ne::Window::Get().Clear(White);
    // }
    printf("It should work.");
    std::cin.get();
    return (0);
}