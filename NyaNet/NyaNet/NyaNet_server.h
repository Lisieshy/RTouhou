/*
** EPITECH PROJECT, 2021
** NyaNet_server
** File description:
** NyaNet_server
*/

#ifndef NYANET_SERVER_H_
#define NYANET_SERVER_H_

#include "NyaNet_common.h"
#include "NyaNet_tsqueue.h"
#include "NyaNet_message.h"
#include "NyaNet_connection.h"

namespace nn {
    template<typename T>
    class IServer {
        public:
            IServer(uint16_t port) :
                m_asioAcceptor(
                    m_asioContext,
                    asio::ip::tcp::endpoint(
                        asio::ip::tcp::v4(),
                        port
                    )
                )
            {

            }

            virtual ~IServer()
            {
                Stop();
            }

            auto Start(
            ) -> bool
            {
                try {
                    WaitForClientConnection();

                    m_threadContext = std::thread(
                        [this]() {
                            m_asioContext.run();
                        }
                    );
                } catch (std::exception& e) {
                    std::stringstream ss;
                    ss << "[SERVER] Exception: " << e.what();
                    nl::nyalog(nl::LogLevel::Error, ss.str());
                    return false;
                }
                nl::nyalog(nl::LogLevel::Info, "[SERVER] Started!");
                return true;
            }

            auto Stop(
            ) -> void
            {
                m_asioContext.stop();

                if (m_threadContext.joinable())
                    m_threadContext.join();

                nl::nyalog(nl::LogLevel::Info, "[SERVER] Stopped!");
            }

            auto WaitForClientConnection(
            ) -> void
            {
                m_asioAcceptor.async_accept(
                    [this](
                        asio::error_code ec,
                        asio::ip::tcp::socket socket
                    ) {
                        if (!ec) {
                            {
                                std::stringstream ss;
                                ss << "[SERVER] New Connection: " << socket.remote_endpoint();
                                nl::nyalog(nl::LogLevel::Info, ss.str());
                            }
                            
                            std::shared_ptr<connection<T>> new_Connection = std::make_shared<connection<T>>(
                                connection<T>::owner::server,
                                m_asioContext,
                                std::move(socket),
                                m_qMessagesIn
                            );

                            if (OnClientConnect(new_Connection)) {
                                m_qConnections.push_back(std::move(new_Connection));
                                m_qConnections.back()->ConnectToClient(nIDCounter++);
                                std::stringstream ss;
                                ss << "[SERVER] New Connection ID [" << m_qConnections.back()->GetID() << "] Approved";
                                nl::nyalog(nl::LogLevel::Info, ss.str());
                            } else {
                                nl::nyalog(nl::LogLevel::Info, "[SERVER] Connection Denied!");
                            }
                        } else {
                            std::stringstream ss;
                            ss << "[SERVER] New Connection Error: " << ec.message();
                            nl::nyalog(nl::LogLevel::Error, ss.str());
                        }

                        WaitForClientConnection();
                    }
                );
            }

            auto MessageClient(
                std::shared_ptr<connection<T>> client,
                const message<T>& msg
            ) -> void
            {
                if (client && client->IsConnected()) {
                    client->Send(msg);
                } else {
                    OnClientDisconnect(client);
                    client.reset();
                    m_qConnections.erase(
                        std::remove(
                            m_qConnections.begin(),
                            m_qConnections.end(),
                            client
                        ),
                        m_qConnections.end()
                    );
                }
            }

            auto MessageAllClients(
                const message<T>& msg,
                std::shared_ptr<connection<T>> pIgnoreClient = nullptr
            ) -> void
            {
                bool bInvalidClientExist = false;

                for (auto& client : m_qConnections) {
                    if (client != pIgnoreClient) {
                        client->Send(msg);
                    } else {
                        OnClientDisconnect(client);
                        client.reset();
                        bInvalidClientExist = true;
                    }
                }

                if (bInvalidClientExist)
                    m_qConnections.erase(
                        std::remove(
                            m_qConnections.begin(),
                            m_qConnections.end(),
                            nullptr
                        ),
                        m_qConnections.end()
                    );
            }

            auto Update(
                size_t nMaxMessages = -1,
                bool bWait = false
            ) -> void
            {
                if (bWait)
                    m_qMessagesIn.wait();

                size_t nMessageCount = 0;
                while (nMessageCount < nMaxMessages && !m_qMessagesIn.empty()) {
                    auto msg = m_qMessagesIn.pop_front();
                    OnMessage(msg.remote, msg.msg);
                    nMessageCount++;
                }
            }

        protected:
            auto virtual OnClientConnect(
                std::shared_ptr<connection<T>> client
            ) -> bool
            {
                return false;
            }

            auto virtual OnClientDisconnect(
                std::shared_ptr<connection<T>> client
            ) -> void
            {

            }

            auto virtual OnMessage(
                std::shared_ptr<connection<T>> client,
                message<T>& msg
            ) -> void
            {

            }

            tsqueue<owned_message<T>> m_qMessagesIn;

            std::deque<std::shared_ptr<connection<T>>> m_qConnections;

            asio::io_context m_asioContext;
            std::thread m_threadContext;

            asio::ip::tcp::acceptor m_asioAcceptor;

            uint32_t nIDCounter = 10000;
    };
}

#endif /* !NYANET_SERVER_H_ */
