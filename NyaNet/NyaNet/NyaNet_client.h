/*
** EPITECH PROJECT, 2021
** NyaNet_client
** File description:
** NyaNet_client
*/

#ifndef NYANET_CLIENT_H_
#define NYANET_CLIENT_H_

#include "NyaNet_common.h"
#include "NyaNet_tsqueue.h"
#include "NyaNet_message.h"
#include "NyaNet_connection.h"

namespace nn {
    template<typename T>
    class IClient
    {
        public:
            IClient() {}
            virtual ~IClient()
            {
                Disconnect();
            }

            auto Connect(
                const std::string& host,
                const uint16_t port
            ) -> bool
            {
                try {
                    asio::ip::tcp::resolver resolver(m_context);
                    asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));

                    m_connection = std::make_unique<connection<T>>(
                        connection<T>::owner::client,
                        m_context,
                        asio::ip::tcp::socket(m_context),
                        m_qMessagesIn
                    );

                    m_connection->ConnectToServer(endpoints);

                    m_thrContext = std::thread([this]() {
                        m_context.run();
                    });

                } catch (std::exception& e) {
                    std::stringstream ss;
                    ss << "IClient Exception: " << e.what();
                    nl::nyalog(nl::LogLevel::Fatal, ss.str());
                    return false;
                }
                return false;
            }

            auto Disconnect(
            ) -> void
            {
                if (IsConnected())
                    m_connection->Disconnect();

                m_context.stop();

                if (m_thrContext.joinable())
                    m_thrContext.join();

                m_connection.release();
            }

            auto IsConnected(
            ) -> bool
            {
                if (m_connection)
                    return m_connection->IsConnected();
                else
                    return false;
            }

            auto Incoming(
            ) -> tsqueue<owned_message<T>>&
            {
                return m_qMessagesIn;
            }

            auto Send(
                const message<T>& msg
            ) -> void
            {
                if (IsConnected()) {
                    m_connection->Send(msg);
                }
            }

        protected:
            asio::io_context m_context;
            
            std::thread m_thrContext;

            std::unique_ptr<connection<T>> m_connection;
        private:
            tsqueue<owned_message<T>> m_qMessagesIn;
    };
}

#endif /* !NYANET_CLIENT_H_ */
