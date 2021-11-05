/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

/**
 * @file        main.cpp
 * @brief       Entrypoint.
 * @details     Contains the entrypoint of the profram.
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

auto main(
    int argc,
    char** argv
) -> int
{
    nl::NyaLogSettings settings;
    settings._filename = "nyalog.log";
    settings._file = true;
    settings._stdout = true;
    settings._level = nl::LogLevel::FATAL;

    nl::nyalog.init(settings);
    nl::nyalog(nl::LogLevel::INFO, "R-Touhou! Configuring everything... Please wait!");

    ne::Graphics::Window::open();

    ne::Scene testScene;

    testScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color>();

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

    std::vector<ne::EntityID> entities(200);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 800);

    std::random_device rd1;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distribColor(0, 255);

    std::random_device rd2;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen2(rd2()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> distribGrav(0.f, 10.f);

    for (auto entity : entities) {
        entity = testScene.coordinator->createEntity();
        testScene.coordinator->addComponent(entity, ne::Transform{
            ne::Math::Vector3f{static_cast<float>(distrib(gen)), 0.f, 0.f},
            ne::Math::Vector3f{0.f, 0.f, 0.f},
            ne::Math::Vector3f{4.f, 4.f, 0.f}
        });
        testScene.coordinator->addComponent(entity, ne::Gravity{
            ne::Math::Vector3f{0.f, static_cast<float>(distribGrav(gen2)), 0.f}
        });
        testScene.coordinator->addComponent(entity, ne::RigidBody{
            ne::Math::Vector3f{0.f, 0.f, 0.f},
            ne::Math::Vector3f{0.f, 0.f, 0.f}
        });
        testScene.coordinator->addComponent(entity, ne::Renderable{});
        testScene.coordinator->addComponent(entity, ne::Color{
            static_cast<unsigned char>(distribColor(gen1)),
            static_cast<unsigned char>(distribColor(gen1)),
            static_cast<unsigned char>(distribColor(gen1)),
            255
        });
    }

    int fps = 0;
    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;

    while (!ne::Graphics::Window::shouldClose()) {
        fps++;
        auto startTime = std::chrono::high_resolution_clock::now();
        ne::Graphics::Window::pollEvent();
        ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char>{
            0, 0, 0, 255
        });
        RenderSystem->update();
        PhysicsSystem->update(dt);
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::seconds{ 1 }) {
            std::string title = "R-Touhou | ";
            oldTime = std::chrono::high_resolution_clock::now();
            ne::Graphics::Window::setTitle(title.append(std::to_string(fps) + " fps"));
            fps = 0;
        }
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
    ne::Graphics::Window::close();
    nl::nyalog(nl::LogLevel::INFO, "Closing down...");
    nl::nyalog.stop();
    return (0);
}