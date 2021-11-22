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
        ne::BulletsFactory bulletFact;
        uint32_t ID; 
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
                else if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::Bonus) {
                    msg.header.id = rt::CustomMsgTypes::SendBonus;
                    auto &transform = coordinator->getComponent<ne::Transform>(entity);
                    auto &uid = coordinator->getComponent<ne::Uid>(entity);
                    auto &type = coordinator->getComponent<ne::EntityType::Type>(entity);
                    msg << transform << uid << type;
                    MessageAllClients(msg);
                }
                else if (coordinator->getComponent<ne::EntityType::Type>(entity) <= ne::EntityType::Type::Player) {
                    msg.header.id = rt::CustomMsgTypes::UpdatePlayer;
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
            msg << client->GetID();
            client->Send(msg);
            auto newEntity = coordinator->createEntity();
            ne::Transform trans;
            trans.position = {350.f, 500.f, 0.f};
            coordinator->addComponent(newEntity, ne::Transform{trans});
            coordinator->addComponent(newEntity, ne::Networkable{});
            coordinator->addComponent(newEntity, ne::RigidBody{});
            coordinator->addComponent(newEntity, ne::Color{});
            coordinator->addComponent(newEntity, ne::Gravity{});
            coordinator->addComponent(newEntity, ne::Uid{client->GetID()});
            coordinator->addComponent(newEntity, ne::EntityType::Type{ne::EntityType::Type::Player});
            coordinator->addComponent(newEntity, ne::Player{});
            coordinator->addComponent(newEntity, ne::WeaponTier{});
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
                    static int shoot = 0;
                    ne::Uid test;
                    ne::Transform transform;
                    msg >> transform >> test;
                    auto NewEntity = coordinator->createEntity();
                    std::shared_ptr<ne::Bullets> NewBullets;

                    transform.position.x += 24;
                    transform.position.y -= 8;
                    int bigbrain = 1;
                    for (auto &c : m_entities) {
                        auto &i = coordinator->getComponent<ne::Uid>(c);
                        if (test.uid == i.uid) {
                            auto &WpTIer = coordinator->getComponent<ne::WeaponTier>(c);
                            bigbrain = WpTIer.WeaponTier;
                        }
                    }
                    if (bigbrain == 1)
                        NewBullets = bulletFact.createBullets("FriendlyBullets");
                    else if (bigbrain == 2)
                        NewBullets = bulletFact.createBullets("BulletsPlT2");
                    else
                        NewBullets = bulletFact.createBullets("BulletsPlT3");
                    coordinator->addComponent(NewEntity, transform);
                    coordinator->addComponent(NewEntity, NewBullets.get()->getGravity());
                    coordinator->addComponent(NewEntity, NewBullets.get()->getRigidBody());
                    coordinator->addComponent(NewEntity, ne::Renderable{});
                    coordinator->addComponent(NewEntity, NewBullets.get()->getType());
                    coordinator->addComponent(NewEntity, ne::Uid { ID });
                    coordinator->addComponent(NewEntity, ne::Networkable{});
                    coordinator->addComponent(NewEntity, NewBullets.get()->getPattern());
                    ID++;
                }
            break;
            case rt::CustomMsgTypes::PlayerUpdate:
                {
                    ne::Transform test;
                    ne::Uid uid;
                    msg >> test >> uid;

                    for (auto &c : m_entities) {
                        auto &i = coordinator->getComponent<ne::Uid>(c);
                        if (uid.uid == i.uid) {
                            auto &newtrans = coordinator->getComponent<ne::Transform>(c);
                            newtrans = test;
                        }
                    }
                }
            break;
            }
        }
};