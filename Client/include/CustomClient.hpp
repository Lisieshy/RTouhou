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
#include "../../Game/Player/Player.hpp"

namespace rt {
    // Defining what types of Messages the server will be capable of handling. THEY MUST BE THE EXACT SAME AS THE SERVER.

    // Creating a CustomClient class that inherits from the NyaNet IClient Interface that holds everything together.
    // Supposedly no need to overwrite any functions, but you can do it if you want.
    class CustomClient : public ne::System, public nn::IClient<CustomMsgTypes>
    {
        public:
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
                                for (auto& entity : m_entities) {
                                    if (receivedUid.uid == coordinator->getComponent<ne::Uid>(entity).uid) {
                                        _found = true;
                                        auto& t = coordinator->getComponent<ne::Transform>(entity);
                                        t = receivedEntity;
                                    }
                                }
                                if (!_found) {
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
                                nn::message<CustomMsgTypes> _msg;
                                _msg.header.id = CustomMsgTypes::PlayerRegisterWithServer;
                                _player.transform.position = {500.0f, 250.0f, 0.0f};
                                _msg << _player.id << _player.transform;
                                Send(_msg);
                            }
                            break;
                            case rt::CustomMsgTypes::AssignPlayerID:
                            {
                                msg >> _player.id;
                                nl::nyalog(nl::LogLevel::Info, "Player ID assigned: " + std::to_string(_player.id.uid));
                            }
                            break;
                            case rt::CustomMsgTypes::AddPlayer:
                            {
                                ne::Player player;
                                msg >> player.id;
                                _players.insert_or_assign(player.id.uid, player);
                                if (player.id.uid == _nPlayerID.uid) {
                                    _waitingForConnection = false;
                                }
                            }
                            break;
                            case rt::CustomMsgTypes::RemovePlayer:
                            {
                                uint32_t removalID = 0;
                                msg >> removalID;
                                _players.erase(removalID);
                            }
                            break;
                            case rt::CustomMsgTypes::UpdatePlayer:
                            {
                                ne::Player player;
                                msg >> player.id;
                                _players.insert_or_assign(player.id.uid, player);
                            }
                            break;
                        }
                    }
                }

                // Send player data to server
                nn::message<CustomMsgTypes> pmsg;
                pmsg.header.id = CustomMsgTypes::UpdatePlayer;
                pmsg << _players[_player.id.uid].id;
                Send(pmsg);
            }
        private:
            ne::EnnemiesFactory fact;
            ne::BulletsFactory bullets;
            std::unordered_map<uint32_t, ne::Player> _players;
            ne::Player _player;
            ne::Uid _nPlayerID = { 5000000 };
            bool _waitingForConnection = true;
    };
}

#endif /* !CUSTOMCLIENT_HPP_ */
