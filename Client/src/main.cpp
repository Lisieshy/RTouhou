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
    /*std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 800);

    std::random_device rd1;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distribColor(15, 235);

    std::random_device rd2;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen2(rd2()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> distribGrav(8.f, 10.f);

    std::random_device rd3;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen3(rd3()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distribY(0, 600);*/

    // for (auto entity : entities) {
        // entity = testScene.coordinator->createEntity();
        // std::shared_ptr<ne::Ennemies> test;
// 
        // if (i < 5)
            // test = fact.createEnnemies("BasicPlane");
        // else if (i < 10)
            // test = fact.createEnnemies("DarkBlue");
        // else if (i < 15)
            // test = fact.createEnnemies("GreenFerry");
        // else if (i < 20)
            // test = fact.createEnnemies("OrangeFerry");
        // else
            // test = fact.createEnnemies("WhiteFerry");
// 
        // testScene.coordinator->addComponent(entity, test.get()->getTransform());
        // testScene.coordinator->addComponent(entity, test.get()->getGravity());
        // testScene.coordinator->addComponent(entity, test.get()->getRigidBody());
        // testScene.coordinator->addComponent(entity, ne::Renderable{});
        // testScene.coordinator->addComponent(entity, test.get()->getColor());
        // testScene.coordinator->addComponent(entity, test.get()->getSkin());
        // i++;
    // }

    ne::Graphics::Window::open();

    int fps = 0;
    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;
    ne::Menu menu;
    ne::Scene menuScene = menu.getScene();
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