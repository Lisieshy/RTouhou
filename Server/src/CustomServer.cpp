/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** CustomServer
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
            for (auto &entity : m_entities) {
                if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::WhiteEnnemy) {
                    if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::BasicEnnemy) {
                        std::cout << "On recoit un BASIC plane" << std::endl;
                    }
                    if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::DarkEnnemy) {
                        std::cout << "On recoit un DARK plane" << std::endl;
                    }
                    if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::GreenEnnemy) {
                        std::cout << "On recoit un GREEN plane" << std::endl;
                    }
                    if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::OrangeEnnemy) {
                        std::cout << "On recoit un ORANGE plane" << std::endl;
                    }
                    if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::WhiteEnnemy) {
                        std::cout << "On recoit un WHITE plane" << std::endl;
                    }
                    msg.header.id = rt::CustomMsgTypes::SendEnnemies;
                    auto &transform = coordinator->getComponent<ne::Transform>(entity);
                    auto &uid = coordinator->getComponent<ne::Uid>(entity);
                    auto &type = coordinator->getComponent<ne::EntityType::Type>(entity);
                    msg << transform << uid << type;
                    MessageAllClients(msg);
                }
                else if (coordinator->getComponent<ne::EntityType::Type>(entity) == ne::EntityType::Type::Bullets) {
                    msg.header.id = rt::CustomMsgTypes::SendBullets;
                    auto &transform = coordinator->getComponent<ne::Transform>(entity);
                    auto &uid = coordinator->getComponent<ne::Uid>(entity);
                    auto &type = coordinator->getComponent<ne::EntityType::Type>(entity);
                    msg << transform << uid << type;
                    MessageAllClients(msg);
                }
            }
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