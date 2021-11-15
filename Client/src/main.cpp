/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

/**
 * @file        main.cpp
 * @brief       Entrypoint.
 * @details     Contains the entrypoint of the program.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

// Pragma definition for Windows to remove the console window.
#pragma comment(linker, "/SUBSYSTEM:windows")

#include <NekoEngine/NekoEngine.hpp>
#include <NekoEngine/Graphics/Window.hpp>
#include <random>
#include <chrono>
#include <sstream>

#include <NyaLog/NyaLog.hpp>
#include <include/CustomClient.hpp>
#include "../../Ennemies/EnnemiesFactory.hpp"
#include "../../Menu/Menu.hpp"
#include "../../Menu/Buttons.hpp"
auto main(
    int argc,
    char** argv
) -> int
{
    nl::nyalog.setLogLevel(nl::LogLevel::Fatal);
    nl::nyalog.init();
    nl::nyalog(nl::LogLevel::Info, "R-Touhou! Configuring everything... Please wait!");

    rt::CustomClient c;
    c.Connect("127.0.0.1", 60000);

    ne::Scene testScene;
    testScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Skin>();

    auto RenderSystem = testScene.coordinator->registerSystem<ne::RenderSystem>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(testScene.coordinator->getComponentType<ne::Color>());
        signature.set(testScene.coordinator->getComponentType<ne::Skin>());
        testScene.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    }



    std::vector<ne::EntityID> entities(25);
    int i = 0;
    ne::EnnemiesFactory fact;
    ne::Graphics::Window::open();

    int fps = 0;
    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;
    ne::Menu menu;
    ne::Scene menuScene = menu.getScene();
    ne::Buttons butt("Play", "Play", ne::Graphics::Window::getWindow());
    while (!ne::Graphics::Window::shouldClose()) {
        fps++;
        menu.Rendering.get()->update();
        menu.PhysicsSystem.get()->update(dt);

        auto startTime = std::chrono::high_resolution_clock::now();
        ne::Graphics::Window::pollEvent(c);
        ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char>{
            0, 0, 0, 255
        });
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::seconds{ 1 }) {
            std::string title = "R-Touhou | ";
            oldTime = std::chrono::high_resolution_clock::now();
            ne::Graphics::Window::setTitle(title.append(std::to_string(fps) + " fps"));
            fps = 0;
        }
        // c.PingServer();
        if (c.IsConnected()) {
            if (!c.Incoming().empty()) {
                auto msg = c.Incoming().pop_front().msg;

                switch (msg.header.id) {
                    case rt::CustomMsgTypes::ServerAccept: 
                    {
                        nl::nyalog(nl::LogLevel::Info, "Server accepted connection!");
                    }
                    break;
                    case rt::CustomMsgTypes::ServerPing:
                    {
                        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
                        std::chrono::system_clock::time_point then;
                        msg >> then;
                        nl::nyalog(nl::LogLevel::Info, "Server ping: " + std::to_string(std::chrono::duration<double>(now - then).count()) + "s");
                    }
                    break;
                    case rt::CustomMsgTypes::ServerMessage:
                    {
                        uint32_t clientID;
                        msg >> clientID;
                        nl::nyalog(nl::LogLevel::Info, "Hello from client " + std::to_string(clientID));
                    }
                    break;
                }
            }
        }
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
    nl::nyalog(nl::LogLevel::Info, "Closing down...");
    ne::Graphics::Window::close();
    nl::nyalog.stop();
    return (0);
}