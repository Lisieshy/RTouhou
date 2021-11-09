/*
** EPITECH PROJECT, 2021
** CustomClient
** File description:
** CustomClient
*/

#ifndef CUSTOMCLIENT_HPP_
#define CUSTOMCLIENT_HPP_

#include <NyaNet/NyaNet.hpp>

namespace rt {
    // Defining what types of Messages the server will be capable of handling. THEY MUST BE THE EXACT SAME AS THE SERVER.
    enum class CustomMsgTypes : uint32_t
    {
        ServerAccept,
        ServerDeny,
        ServerPing,
        MessageAll,
        ServerMessage,
    };

    // Creating a CustomClient class that inherits from the NyaNet IClient Interface that holds everything together.
    // Supposedly no need to overwrite any functions, but you can do it if you want.
    class CustomClient : public nn::IClient<CustomMsgTypes>
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
    };
}

#endif /* !CUSTOMCLIENT_HPP_ */
