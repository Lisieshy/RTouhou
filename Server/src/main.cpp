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

#include <NyaNet/NyaNet.hpp>
#include <NyaLog/NyaLog.hpp>
#include <iostream>

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

    while (1)
    {
        server.Update(-1, true);
    }

    nl::nyalog.stop();
    return 0;
}