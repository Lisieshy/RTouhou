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

class CustomServer : public ne::System, public nn::IServer<rt::CustomMsgTypes>
{
    public:
        CustomServer(uint16_t nPort = 60000) : nn::IServer<rt::CustomMsgTypes>(nPort)
        {
        }

        virtual auto SendDataToClients(
        ) -> void
        {
            nn::message<rt::CustomMsgTypes> msg;
            msg.header.id = rt::CustomMsgTypes::SendData;
            for (auto &entity : m_entities) {
                auto &transform = coordinator->getComponent<ne::Transform>(entity);
                auto &rigidBody = coordinator->getComponent<ne::RigidBody>(entity);
                auto &color = coordinator->getComponent<ne::Color>(entity);
                auto &uid = coordinator->getComponent<ne::Uid>(entity);
                auto &skin = coordinator->getComponent<ne::Skin>(entity);
                msg << skin << transform << color << uid;
                MessageAllClients(msg);
                // nl::nyalog(nl::LogLevel::Info, "The entity id sended is : " + std::to_string(uid.uid) + " and the color of the entity is : " + std::to_string(color.r) + "/" + std::to_string(color.g) + "/" + std::to_string(color.b));
            }
            // std::vector<ne::Transform> transforms;
            // for (auto &entity : m_entities) {
            //     transforms.push_back(coordinator->getComponent<ne::Transform>(entity));
            // }
            // msg << transforms;
            // MessageAllClients(msg);
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
    uint32_t entityID = 0;
    ne::Scene testScene;

    testScene.coordinator->registerComponent<ne::Transform, ne::Gravity, ne::RigidBody, ne::Networkable, ne::Color, ne::Uid, ne::Skin>();

    auto PhysicsSystem = testScene.coordinator->registerSystem<ne::PhysicsSystem>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::RigidBody>());
        signature.set(testScene.coordinator->getComponentType<ne::Gravity>());
        testScene.coordinator->setSystemSignature<ne::PhysicsSystem>(signature);
    }

    auto NetworkSystem = testScene.coordinator->registerSystem<CustomServer>(testScene.coordinator);
    {
        ne::Signature signature;
        signature.set(testScene.coordinator->getComponentType<ne::Transform>());
        signature.set(testScene.coordinator->getComponentType<ne::RigidBody>());
        signature.set(testScene.coordinator->getComponentType<ne::Color>());
        signature.set(testScene.coordinator->getComponentType<ne::Networkable>());
        testScene.coordinator->setSystemSignature<CustomServer>(signature);
    }

    std::vector<ne::EntityID> entities(100);
    ne::EnnemiesFactory fact;

    for (auto entity : entities) {
        if (entityID <= 10) {
            entity = testScene.coordinator->createEntity();
            std::shared_ptr<ne::Ennemies> test = fact.createEnnemies("BasicPlane");
            testScene.coordinator->addComponent(entity, test.get()->getTransform());
            testScene.coordinator->addComponent(entity, test.get()->getGravity());
            testScene.coordinator->addComponent(entity, test.get()->getRigidBody());
            testScene.coordinator->addComponent(entity, ne::Renderable{});
            testScene.coordinator->addComponent(entity, test.get()->getColor());
            testScene.coordinator->addComponent(entity, test.get()->getSkin());
            testScene.coordinator->addComponent(entity, ne::Color{});
            testScene.coordinator->addComponent(entity, ne::Uid{entityID});
        }
        entityID++;
    }
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
    //     testScene.coordinator->addComponent(entity, ne::Networkable{});
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
    //     testScene.coordinator->addComponent(entity, ne::Color{
    //         static_cast<uint8_t>(distribColor(gen1)),
    //         static_cast<uint8_t>(distribColor(gen1)),
    //         static_cast<uint8_t>(distribColor(gen1)),
    //         255
    //     });
    //     testScene.coordinator->addComponent(entity, ne::Uid{entityID});
    //     entityID++;
    // }

    NetworkSystem->Start();

    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;
    int fps = 0;

    while (1) {
        auto startTime = std::chrono::high_resolution_clock::now();
        fps++;
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::milliseconds{ 20 }) {
            oldTime = std::chrono::high_resolution_clock::now();
            NetworkSystem->SendDataToClients();
            fps = 0;
        }
        PhysicsSystem->update(dt);
        NetworkSystem->Update(-1, false);
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }

    NetworkSystem->Stop();

    nl::nyalog.stop();
    return 0;
}