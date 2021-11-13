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
// #pragma comment(linker, "/SUBSYSTEM:windows")

#include <NekoEngine/NekoEngine.hpp>
#include <NekoEngine/Graphics/Window.hpp>
#include <random>
#include <chrono>
#include <sstream>

#include <NyaLog/NyaLog.hpp>
#include <include/CustomClient.hpp>

auto main(
    int argc,
    char** argv
) -> int
{
    nl::nyalog.setLogLevel(nl::LogLevel::Fatal);
    nl::nyalog.init();
    nl::nyalog(nl::LogLevel::Info, "R-Touhou! Configuring everything... Please wait!");

    // rt::CustomClient c;
    // c.Connect("127.0.0.1", 60000);

    ne::Scene testScene;

    testScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color, ne::Uid>();

    auto RenderSystem = testScene.coordinator->registerSystem<ne::RenderSystem>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(testScene.coordinator->getComponentType<ne::Color>());
        testScene.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    }

    auto PhysicsSystem = testScene.coordinator->registerSystem<ne::PhysicsSystem>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::RigidBody>());
        signature.set(testScene.coordinator->getComponentType<ne::Gravity>());
        testScene.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }

    auto ClientSystem = testScene.coordinator->registerSystem<rt::CustomClient>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::Renderable>());
        signature.set(testScene.coordinator->getComponentType<ne::Color>());
        testScene.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }

    ClientSystem->Connect("127.0.0.1", 60000);

    std::vector<ne::EntityID> entities(10);

    std::random_device rd1;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distribColor(15, 235);
    uint32_t entityID = 0;
    for (auto entity : entities) {
        entity = testScene.coordinator->createEntity();
        testScene.coordinator->addComponent(entity, ne::Transform{
            ne::Math::Vector3f{0.f, 0.f, 0.f},
            ne::Math::Vector3f{0.f, 0.f, 0.f},
            ne::Math::Vector3f{4.f, 4.f, 0.f}
        });
        testScene.coordinator->addComponent(entity, ne::RigidBody{
            ne::Math::Vector3f{0.f, 0.f, 0.f},
            ne::Math::Vector3f{0.f, 0.f, 0.f}
        });
        testScene.coordinator->addComponent(entity, ne::Renderable{});
        testScene.coordinator->addComponent(entity, ne::Color{});
        testScene.coordinator->addComponent(entity, ne::Uid{entityID});
        entityID++;
    }

    ne::Graphics::Window::open();

    int fps = 0;
    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;

    while (!ne::Graphics::Window::shouldClose()) {
        fps++;
        auto startTime = std::chrono::high_resolution_clock::now();
        ne::Graphics::Window::pollEvent(ClientSystem);
        ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char>{
            0, 0, 0, 255
        });
        RenderSystem->update();
        ClientSystem->OnMessage();
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::seconds{ 1 }) {
            std::string title = "R-Touhou | ";
            oldTime = std::chrono::high_resolution_clock::now();
            ne::Graphics::Window::setTitle(title.append(std::to_string(fps) + " fps"));
            fps = 0;
        }
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
    nl::nyalog(nl::LogLevel::Info, "Closing down...");
    ne::Graphics::Window::close();
    nl::nyalog.stop();
    return (0);
}