/*
** EPITECH PROJECT, 2021
** CustomClient
** File description:
** CustomClient
*/

#ifndef CUSTOMCLIENT_HPP_
#define CUSTOMCLIENT_HPP_

#include <NyaNet/NyaNet.hpp>
#include <NekoEngine/NekoEngine.hpp>
#include "../../Game/Ennemies/EnnemiesFactory.hpp"
#include "../../Game/Bullets/BulletsFactory.hpp"
#include "../../Game/Bonus/BonusFactory.hpp"
#include "Sound.hpp"
#include "../../Game/Player/Player.hpp"

namespace rt {
    // Defining what types of Messages the server will be capable of handling. THEY MUST BE THE EXACT SAME AS THE SERVER.

    // Creating a CustomClient class that inherits from the NyaNet IClient Interface that holds everything together.
    // Supposedly no need to overwrite any functions, but you can do it if you want.
    class CustomClient : public ne::System, public nn::IClient<CustomMsgTypes>
    {
        public:
            ne::EntityID _player;
            // Basic function for handling ping.
            // NEVER, EVER USE THE SYSTEM CLOCK FOR A PING LIKE THAT
            // IT'S NOT A GOOD IDEA.
            // It's just here for demonstration purposes, since the local server will have the same clock as the client.
            void PingServer()
            {
                nn::message<CustomMsgTypes> msg;
                msg.header.id = CustomMsgTypes::ServerPing;

                std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

                msg << now;
                Send(msg);
            }

            // Broadcast data to all clients connected to the server.
            void MessageAll()
            {
                nn::message<CustomMsgTypes> msg;
                msg.header.id = CustomMsgTypes::MessageAll;
                Send(msg);
            }

            void OnMessage()
            {
                if (IsConnected()) {
                    while (!Incoming().empty()) {
                        auto msg = Incoming().pop_front().msg;
                        switch (msg.header.id) {
                            case rt::CustomMsgTypes::ServerAccept:
                            {
                                nl::nyalog(nl::LogLevel::Info, "Server accepted connection!");
                            }
                            break;
                            case rt::CustomMsgTypes::SendEnnemies:
                            {
                                bool _found = false;
                                ne::Transform receivedEntity;
                                ne::Uid receivedUid;
                                ne::EntityType::Type receivedType;
                                msg >> receivedType >> receivedUid >> receivedEntity;
                                // std::cout << "Received UID from enemy : " << receivedUid.uid << std::endl;
                                for (auto& entity : m_entities) {
                                    if (receivedUid.uid == coordinator->getComponent<ne::Uid>(entity).uid) {
                                        _found = true;
                                        auto& t = coordinator->getComponent<ne::Transform>(entity);
                                        t = receivedEntity;
                                    }
                                }
                                if (!_found) {
                                    sound.BadGuySound.play();
                                    if (receivedType <= ne::EntityType::Type::WhiteEnnemy) {
                                        auto newEntity = coordinator->createEntity();
                                        std::shared_ptr<ne::Ennemies> test;
                                        if (receivedType == ne::EntityType::Type::BasicEnnemy)
                                            test = fact.createEnnemies("BasicPlane");
                                        if (receivedType == ne::EntityType::Type::DarkEnnemy)
                                            test = fact.createEnnemies("DarkBlue");
                                        if (receivedType == ne::EntityType::Type::GreenEnnemy)
                                            test = fact.createEnnemies("GreenFerry");
                                        if (receivedType == ne::EntityType::Type::OrangeEnnemy)
                                            test = fact.createEnnemies("OrangeFerry");
                                        if (receivedType == ne::EntityType::Type::WhiteEnnemy)
                                            test = fact.createEnnemies("WhiteFerry");
                                        test.get()->setTransform(receivedEntity);
                                        test.get()->setType(receivedType);
                                        coordinator->addComponent(newEntity, receivedEntity);
                                        coordinator->addComponent(newEntity, test.get()->getRigidBody());
                                        coordinator->addComponent(newEntity, ne::Renderable{});
                                        coordinator->addComponent(newEntity, test.get()->getColor());
                                        coordinator->addComponent(newEntity, test.get()->getSkin());
                                        coordinator->addComponent(newEntity, ne::Uid{ receivedUid });
                                        coordinator->addComponent(newEntity, test.get()->getAlien());
                                        coordinator->addComponent(newEntity, test.get()->getType());
                                        coordinator->addComponent(newEntity, test.get()->getPattern());
                                        coordinator->addComponent(newEntity, ne::Animation{});
                                    }
                                }
                            }
                            break;
                            case rt::CustomMsgTypes::SendBullets:
                            {
                                bool _found = false;
                                ne::Transform receivedEntity;
                                ne::Uid receivedUid;
                                ne::EntityType::Type receivedType;
                                msg >> receivedType >> receivedUid >> receivedEntity;

                                for (auto& entity : m_entities) {
                                    if (receivedUid.uid == coordinator->getComponent<ne::Uid>(entity).uid) {
                                        _found = true;
                                        auto& t = coordinator->getComponent<ne::Transform>(entity);
                                        t = receivedEntity;
                                    }
                                }
                                if (!_found) {
                                        sound.GunSound.play();
                                        auto newEntity = coordinator->createEntity();
                                        std::shared_ptr<ne::Bullets> bulletsCreated;
                                        if (receivedType == ne::EntityType::Type::WhiteBullets)
                                            bulletsCreated = bullets.createBullets("BasicWhiteBullets");
                                        else if (receivedType == ne::EntityType::Type::Tier2Bullets)
                                            bulletsCreated = bullets.createBullets("Tier2Bullets");
                                        else if (receivedType == ne::EntityType::Type::FriendlyBullets)
                                            bulletsCreated = bullets.createBullets("FriendlyBullets");
                                        else
                                            bulletsCreated = bullets.createBullets("Tier3Bullets");                                        
                                        bulletsCreated.get()->setTransform(receivedEntity);
                                        bulletsCreated.get()->setType(receivedType);
                                        coordinator->addComponent(newEntity, receivedEntity);
                                        coordinator->addComponent(newEntity, bulletsCreated.get()->getRigidBody());
                                        coordinator->addComponent(newEntity, ne::Renderable{});
                                        coordinator->addComponent(newEntity, bulletsCreated.get()->getColor());
                                        coordinator->addComponent(newEntity, bulletsCreated.get()->getSkin());
                                        coordinator->addComponent(newEntity, ne::Uid{ receivedUid });
                                        coordinator->addComponent(newEntity, bulletsCreated.get()->getType());
                                        coordinator->addComponent(newEntity, bulletsCreated.get()->getPattern());
                                }
                            }
                            break;
                            case rt::CustomMsgTypes::SendBonus:
                            {
                                bool _found = false;
                                ne::Transform receivedEntity;
                                ne::Uid receivedUid;
                                ne::EntityType::Type receivedType;
                                msg >> receivedType >> receivedUid >> receivedEntity;
                                for (auto& entity : m_entities) {
                                    if (receivedUid.uid == coordinator->getComponent<ne::Uid>(entity).uid) {
                                        _found = true;
                                        auto& t = coordinator->getComponent<ne::Transform>(entity);
                                        t = receivedEntity;
                                    }
                                }
                                if (!_found) {
                                    if (receivedType <= ne::EntityType::Type::ScoreUp) {
                                        auto newEntity = coordinator->createEntity();
                                        std::shared_ptr<ne::Bonus> test;

                                        test = BonusFactor.createBonus("ScoreUp");
                                        test.get()->setTransform(receivedEntity);
                                        coordinator->addComponent(newEntity, receivedEntity);
                                        coordinator->addComponent(newEntity, ne::Renderable{});
                                        coordinator->addComponent(newEntity, ne::Uid{ receivedUid });
                                        coordinator->addComponent(newEntity, test.get()->getSkin());
                                        coordinator->addComponent(newEntity, test.get()->getType());
                                        coordinator->addComponent(newEntity, test.get()->getPattern());
                                        coordinator->addComponent(newEntity, ne::RigidBody{});
                                        coordinator->addComponent(newEntity, ne::Color{});
                                    }
                                }
                            }
                            break;
                            case rt::CustomMsgTypes::SendData:
                            {
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
                            case rt::CustomMsgTypes::AcceptedPlayer:
                            {
                                uint32_t id;
                                msg >> id;
                                coordinator->addComponent(_player, ne::Uid{id});
                                nl::nyalog(nl::LogLevel::Info, "Client has been accepted by the server");
                            }
                            break;
                        }
                    }
                }
            }
        private:
            ne::EnnemiesFactory fact;
            ne::BulletsFactory bullets;
            ne::BonusFactory BonusFactor;
            ne::Sound sound;
            bool _waitingForConnection = true;
    };
}

#endif /* !CUSTOMCLIENT_HPP_ */
