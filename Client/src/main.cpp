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
#include <NyaNet/NyaNet.hpp>

#include <SFML/Graphics.hpp>


enum class CustomMsgTypes : uint32_t
{
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
};

class CustomClient : public nn::IClient<CustomMsgTypes>
{
    public:
        void PingServer()
        {
            nn::message<CustomMsgTypes> msg;
            msg.header.id = CustomMsgTypes::ServerPing;

            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

            msg << now;
            Send(msg);
        }

        void MessageAll()
        {
            nn::message<CustomMsgTypes> msg;
            msg.header.id = CustomMsgTypes::MessageAll;
            Send(msg);
        }
};

auto main(
    int argc,
    char** argv
) -> int
{
    nl::nyalog.setLogLevel(nl::LogLevel::FATAL);
    nl::nyalog.init();
    nl::nyalog(nl::LogLevel::INFO, "R-Touhou! Configuring everything... Please wait!");

    CustomClient c;
    c.Connect("127.0.0.1", 60000);

    sf::RenderWindow window(sf::VideoMode(800, 600), "R-Touhou!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Escape)
                    window.close();
                if (event.key.code == sf::Keyboard::Key::A) {
                    c.PingServer();
                    nl::nyalog(nl::LogLevel::INFO, "Ping sent!");
                }
                if (event.key.code == sf::Keyboard::Key::Z) {
                    c.MessageAll();
                    nl::nyalog(nl::LogLevel::INFO, "Message All sent!");
                }
            }
        }
        if (c.IsConnected()) {
            if (!c.Incoming().empty()) {
                auto msg = c.Incoming().pop_front().msg;

                switch (msg.header.id) {
                    case CustomMsgTypes::ServerAccept:
                    {
                        nl::nyalog(nl::LogLevel::INFO, "Server accepted connection!");
                    }
                    break;
                    case CustomMsgTypes::ServerPing:
                    {
                        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
                        std::chrono::system_clock::time_point then;
                        msg >> then;
                        nl::nyalog(nl::LogLevel::INFO, "Server ping: " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(now - then).count()) + "ms");
                    }
                    break;
                    case CustomMsgTypes::ServerMessage:
                    {
                        uint32_t clientID;
                        msg >> clientID;
                        nl::nyalog(nl::LogLevel::INFO, "Hello from client " + std::to_string(clientID));
                    }
                    break;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    // CustomClient c;
    // c.Connect("127.0.0.1", 5000);
    // c.FireBullet(2.0f, 5.0f);

    // ne::Scene testScene;

    // testScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Renderable, ne::Color>();

    // auto RenderSystem = testScene.coordinator->registerSystem<ne::RenderSystem>(testScene.coordinator);
    // {
    //     ne::Signature signature;
    //     signature.set(testScene.coordinator->getComponentType<ne::Transform>());
    //     signature.set(testScene.coordinator->getComponentType<ne::Renderable>());
    //     signature.set(testScene.coordinator->getComponentType<ne::Color>());
    //     testScene.coordinator->setSystemSignature<ne::RenderSystem>(signature);
    // }

    // auto PhysicsSystem = testScene.coordinator->registerSystem<ne::PhysicsSystem>(testScene.coordinator);
    // {
    //     ne::Signature signature;
    //     signature.set(testScene.coordinator->getComponentType<ne::Transform>());
    //     signature.set(testScene.coordinator->getComponentType<ne::RigidBody>());
    //     signature.set(testScene.coordinator->getComponentType<ne::Gravity>());
    //     testScene.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    // }

    // std::vector<ne::EntityID> entities(2);

    // std::random_device rd;  //Will be used to obtain a seed for the random number engine
    // std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    // std::uniform_int_distribution<> distrib(0, 800);

    // std::random_device rd1;  //Will be used to obtain a seed for the random number engine
    // std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
    // std::uniform_int_distribution<> distribColor(15, 235);

    // std::random_device rd2;  //Will be used to obtain a seed for the random number engine
    // std::mt19937 gen2(rd2()); //Standard mersenne_twister_engine seeded with rd()
    // std::uniform_real_distribution<> distribGrav(8.f, 10.f);

    // std::random_device rd3;  //Will be used to obtain a seed for the random number engine
    // std::mt19937 gen3(rd3()); //Standard mersenne_twister_engine seeded with rd()
    // std::uniform_int_distribution<> distribY(0, 600);

    // for (auto entity : entities) {
    //     entity = testScene.coordinator->createEntity();
    //     testScene.coordinator->addComponent(entity, ne::Transform{
    //         ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
    //         ne::Math::Vector3f{0.f, 0.f, 0.f},
    //         ne::Math::Vector3f{4.f, 4.f, 0.f}
    //     });
    //     testScene.coordinator->addComponent(entity, ne::Gravity{
    //         ne::Math::Vector3f{0.f, static_cast<float>(distribGrav(gen2)), 0.f}
    //     });
    //     testScene.coordinator->addComponent(entity, ne::RigidBody{
    //         ne::Math::Vector3f{0.f, 0.f, 0.f},
    //         ne::Math::Vector3f{0.f, 0.f, 0.f}
    //     });
    //     testScene.coordinator->addComponent(entity, ne::Renderable{});
    //     testScene.coordinator->addComponent(entity, ne::Color{
    //         static_cast<unsigned char>(distribColor(gen1)),
    //         static_cast<unsigned char>(distribColor(gen1)),
    //         static_cast<unsigned char>(distribColor(gen1)),
    //         255
    //     });
    //     std::string message = "Entity[" + std::to_string(entity) + "]" + " created.";
    //     nl::nyalog(nl::LogLevel::INFO, message);
    // }

    // ne::Graphics::Window::open();

    // int fps = 0;
    // auto oldTime = std::chrono::high_resolution_clock::now();
    // float dt = 0.0f;

    // while (!ne::Graphics::Window::shouldClose()) {
    //     fps++;
    //     auto startTime = std::chrono::high_resolution_clock::now();
    //     ne::Graphics::Window::pollEvent();
    //     ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char>{
    //         0, 0, 0, 255
    //     });
    //     RenderSystem->update();
    //     PhysicsSystem->update(dt);
    //     if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::seconds{ 1 }) {
    //         std::string title = "R-Touhou | ";
    //         oldTime = std::chrono::high_resolution_clock::now();
    //         ne::Graphics::Window::setTitle(title.append(std::to_string(fps) + " fps"));
    //         fps = 0;
    //     }
    //     auto stopTime = std::chrono::high_resolution_clock::now();
    //     dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    // }
    // nl::nyalog(nl::LogLevel::INFO, "Closing down...");
    // ne::Graphics::Window::close();
    nl::nyalog.stop();
    return (0);
}