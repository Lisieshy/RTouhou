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
#include "../../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include <NyaNet/NyaNet.hpp>
#include <NyaLog/NyaLog.hpp>
#include <unordered_map>
#include <vector>
#include "../../Game/Player/Player.hpp"

class CustomServer : public ne::System, public nn::IServer<rt::CustomMsgTypes>
{
    public:
        CustomServer(uint16_t nPort = 60000) : nn::IServer<rt::CustomMsgTypes>(nPort)
        {
        }

        std::unordered_map<uint32_t, ne::Player> m_mapPlayersRoster;
        std::vector<uint32_t> m_garbageIDs;

        virtual auto SendDataToClients(
        ) -> void
        {
            nn::message<rt::CustomMsgTypes> msg;
            for (auto &entity : m_entities) {
                if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::WhiteEnnemy) {
                    msg.header.id = rt::CustomMsgTypes::SendEnnemies;
                    auto &transform = coordinator->getComponent<ne::Transform>(entity);
                    auto &uid = coordinator->getComponent<ne::Uid>(entity);
                    auto &type = coordinator->getComponent<ne::EntityType::Type>(entity);
                    msg << transform << uid << type;
                    MessageAllClients(msg);
                }
                else if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::Bullets) {
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

        void OnClientValidated(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client) override
        {
            nn::message<rt::CustomMsgTypes> msg;
            msg.header.id = rt::CustomMsgTypes::AcceptedPlayer;
            client->Send(msg);
        }

        bool OnClientConnect(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client) override
        {
            return true;
        }

        void OnClientDisconnect(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client) override
        {
            std::stringstream ss;
            ss << "Removing client [" << client->GetID() << "]";
            nl::nyalog(nl::LogLevel::Info, ss.str());
            if (client) {
                if (m_mapPlayersRoster.find(client->GetID()) == m_mapPlayersRoster.end()) {
                    // Nothing to do
                } else {
                    auto& pd = m_mapPlayersRoster[client->GetID()];
                    nl::nyalog(nl::LogLevel::Warning, "Ungraceful removal!: " + std::to_string(pd.id.uid));
                    m_mapPlayersRoster.erase(client->GetID());
                    m_garbageIDs.push_back(client->GetID());
                }
            }
        }

        void OnMessage(std::shared_ptr<nn::connection<rt::CustomMsgTypes>> client, nn::message<rt::CustomMsgTypes> &msg) override
        {
            if (!m_garbageIDs.empty()) {
                for (auto pid : m_garbageIDs) {
                    nn::message<rt::CustomMsgTypes> m;
                    m.header.id = rt::CustomMsgTypes::RemovePlayer;
                    m << pid;
                    nl::nyalog(nl::LogLevel::Info, "Removing player: " + std::to_string(pid));
                    MessageAllClients(m);
                }
                m_garbageIDs.clear();
            }

            switch (msg.header.id) {
            case rt::CustomMsgTypes::PlayerRegisterWithServer:
                {
                    ne::Player player;
                    msg >> player.id >> player.transform;
                    player.id.uid = client->GetID();

                    m_mapPlayersRoster.insert_or_assign(player.id.uid, player);


                    nn::message<rt::CustomMsgTypes> mSendID;
                    mSendID.header.id = rt::CustomMsgTypes::AssignPlayerID;
                    mSendID << player.id;
                    MessageClient(client, mSendID);


                    nn::message<rt::CustomMsgTypes> mAddPlayer;
                    mAddPlayer.header.id = rt::CustomMsgTypes::AddPlayer;
                    mAddPlayer << player.id;

                    MessageAllClients(mAddPlayer);
                    for (const auto& p : m_mapPlayersRoster) {
                        nn::message<rt::CustomMsgTypes> mAddOtherPlayer;
                        mAddOtherPlayer.header.id = rt::CustomMsgTypes::AddPlayer;
                        std::cout << p.second.id.uid << std::endl;
                        mAddOtherPlayer << p.second.id;
                        MessageClient(client, mAddOtherPlayer);
                    }
                }
            break;
            case rt::CustomMsgTypes::UpdatePlayer:
                {
                    MessageAllClients(msg, client);
                }
            break;
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
            case rt::CustomMsgTypes::PlayerIsShooting:
                {
                    std::cout << "Player is shooting" << std::endl;
                }
            break;
            }
        }
};