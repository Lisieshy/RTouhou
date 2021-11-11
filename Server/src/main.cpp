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
 * @date        07/11/2021
 */

#include <random>
#include <chrono>
#include <sstream>
#include <iostream>
#include <NekoEngine/NekoEngine.hpp>
#include <NyaNet/NyaNet.hpp>
#include <NyaLog/NyaLog.hpp>

class CustomServer : public nn::IServer<rt::CustomMsgTypes>
{
    public:
        CustomServer(uint16_t nPort) : nn::IServer<rt::CustomMsgTypes>(nPort)
        {
        }

    protected:
        virtual bool OnClientConnect(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client)
        {
            nn::message<rt::CustomMsgTypes> msg;
            msg.header.id = rt::CustomMsgTypes::ServerAccept;
            client->Send(msg);
            return true;
        }

        virtual void OnClientDisconnect(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client)
        {
            std::stringstream ss;
            ss << "Removing client [" << client->GetID() << "]";
            nl::nyalog(nl::LogLevel::Info, ss.str());
        }

        virtual void OnMessage(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client, nn::message<rt::CustomMsgTypes> &msg)
        {
            switch (msg.header.id) {
            case rt::CustomMsgTypes::ServerPing:
                {
                    std::stringstream ss;
                    ss << "[" << client->GetID() << "]: Server Ping";
                    nl::nyalog(nl::LogLevel::Info, ss.str());

                    client->Send(msg);
                }
            break;
            case rt::CustomMsgTypes::MessageAll:
                {
                    std::stringstream ss;
                    ss << "[" << client->GetID() << "]: Message All";
                    nl::nyalog(nl::LogLevel::Info, ss.str());

                    nn::message<rt::CustomMsgTypes> msg;
                    msg.header.id = rt::CustomMsgTypes::ServerMessage;
                    msg << client->GetID();
                    MessageAllClients(msg, client);
                }
            break;
            }
        }
};

auto main(
    int argc,
    char **argv
) -> int {
    nl::nyalog.setFilename("Server.log");
    nl::nyalog.init();
    nl::nyalog.setLogLevel(nl::LogLevel::Fatal);

    CustomServer server(60000);

    server.Start();
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

    std::vector<ne::EntityID> entities(1);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
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
    std::uniform_int_distribution<> distribY(0, 600);

    for (auto entity : entities) {
        entity = testScene.coordinator->createEntity();
        testScene.coordinator->addComponent(entity, ne::Transform{
            ne::Math::Vector3f{static_cast<float>(distrib(gen)), static_cast<float>(distribY(gen3)), 0.f},
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
    while (1)
    {
        server.Update(-1, false);
    }

    nl::nyalog.stop();
    return 0;
}