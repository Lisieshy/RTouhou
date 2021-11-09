/*
** EPITECH PROJECT, 2021
** NyaNet_connection
** File description:
** NyaNet_connection
*/

#ifndef NYANET_CONNECTION_H_
#define NYANET_CONNECTION_H_

#include "NyaNet_common.h"
#include "NyaNet_tsqueue.h"
#include "NyaNet_message.h"

namespace nn {
    template<typename T>
    class connection : public std::enable_shared_from_this<connection<T>>
    {
        public:
            enum class owner
            {
                server,
                client
            };

            connection(
                owner parent,
                asio::io_context& asioContext,
                asio::ip::tcp::socket socket,
                tsqueue<owned_message<T>>& qIn
            ) :
                m_asioContext(asioContext),
                m_socket(std::move(socket)),
                m_qMessagesIn(qIn)
            {
                m_nOwnerType = parent;
            }

            virtual ~connection()
            {

            }

            auto ConnectToClient(
                uint32_t uid = 0
            ) -> void
            {
                if (m_nOwnerType == owner::server) {
                    if (m_socket.is_open()) {
                        id = uid;
                        ReadHeader();
                    }
                }
            }

            auto ConnectToServer(
                const asio::ip::tcp::resolver::results_type& endpoints
            ) -> void
            {
                if (m_nOwnerType == owner::client) {
                    asio::async_connect(
                        m_socket,
                        endpoints,
                        [this](
                            const std::error_code ec,
                            const asio::ip::tcp::endpoint& endpoint
                        ) {
                            if (!ec) {
                                ReadHeader();
                            }
                        }
                    );
                }
            }

            auto Disconnect(
            ) -> void
            {
                if (IsConnected())
                    asio::post(
                        m_asioContext,
                        [this](
                        ) {
                            m_socket.close();
                        }
                    );
            }

            auto IsConnected(
            ) -> bool const
            {
                return m_socket.is_open();
            }

            auto Send(
                const message<T>& msg
            ) -> void
            {
                asio::post(
                    m_asioContext,
                    [this, msg](
                    ) {
                        bool bWritingMessage = !m_qMessagesOut.empty();
                        m_qMessagesOut.push_back(msg);
                        if (!bWritingMessage) {
                            WriteHeader();
                        }
                    }
                );
            }

            auto GetID(
            ) -> uint32_t const
            {
                return id;
            }

        private:
            auto ReadHeader(
            ) -> void
            {
                asio::async_read(
                    m_socket,
                    asio::buffer(
                        &m_msgTemporaryIn.header,
                        sizeof(message_header<T>)
                    ),
                    [this](
                        asio::error_code ec,
                        std::size_t length
                    ) {
                        if (!ec) {
                            if (m_msgTemporaryIn.header.size > 0) {
                                m_msgTemporaryIn.body.resize(
                                    m_msgTemporaryIn.header.size
                                );
                                ReadBody();
                            } else {
                                AddToIncomingMessageQueue();
                            }
                        } else {
                            std::stringstream ss;
                            ss << "[SERVER] ID[" << id << "] Read Header Fail.";
                            nl::nyalog(nl::LogLevel::Error, ss.str());
                            // std::cerr << ss.str() << std::endl;
                            m_socket.close();
                        }
                    }
                );
            }

            auto ReadBody(
            ) -> void
            {
                asio::async_read(
                    m_socket,
                    asio::buffer(
                        m_msgTemporaryIn.body.data(),
                        m_msgTemporaryIn.body.size()
                    ),
                    [this](
                        asio::error_code ec,
                        std::size_t length
                    ) {
                        if (!ec) {
                            AddToIncomingMessageQueue();
                        } else {
                            std::stringstream ss;
                            ss << "[SERVER] ID[" << id << "] Read Body Fail.";
                            nl::nyalog(nl::LogLevel::Error, ss.str());
                            // std::cerr << ss.str() << std::endl;
                            m_socket.close();
                        }
                    }
                );
            }

            auto WriteHeader(
            ) -> void
            {
                asio::async_write(
                    m_socket,
                    asio::buffer(
                        &m_qMessagesOut.front().header,
                        sizeof(message_header<T>)
                    ),
                    [this](
                        asio::error_code ec,
                        std::size_t length
                    ) {
                        if (!ec) {
                            if (m_qMessagesOut.front().body.size() > 0)
                                WriteBody();
                            else {
                                m_qMessagesOut.pop_front();
                                if (!m_qMessagesOut.empty())
                                    WriteHeader();
                            }
                        } else {
                            std::stringstream ss;
                            ss << "[SERVER] ID[" << id << "] Write Header Fail.";
                            nl::nyalog(nl::LogLevel::Error, ss.str());
                            // std::cerr << ss.str() << std::endl;
                            m_socket.close();
                        }
                    }
                );
            }

            auto WriteBody(
            ) -> void
            {
                asio::async_write(
                    m_socket,
                    asio::buffer(
                        &m_qMessagesOut.front().header,
                        sizeof(message_header<T>)
                    ),
                    [this](
                        asio::error_code ec,
                        std::size_t length
                    ) {
                        if (!ec) {
                            m_qMessagesOut.pop_front();

                            if (!m_qMessagesOut.empty())
                                WriteHeader();
                        } else {
                            std::stringstream ss;
                            ss << "[SERVER] ID[" << id << "] Write Body Fail.";
                            nl::nyalog(nl::LogLevel::Error, ss.str());
                            // std::cerr << ss.str() << std::endl;
                            m_socket.close();
                        }
                    }
                );
            }

            auto AddToIncomingMessageQueue(
            ) -> void
            {
                if (m_nOwnerType == owner::server) {
                    m_qMessagesIn.push_back({
                        this->shared_from_this(),
                        m_msgTemporaryIn
                    });
                } else {
                    m_qMessagesIn.push_back({
                        nullptr,
                        m_msgTemporaryIn
                    });
                }

                ReadHeader();
            }

        protected:
            asio::ip::tcp::socket m_socket;

            asio::io_context& m_asioContext;

            tsqueue<message<T>> m_qMessagesOut;

            tsqueue<owned_message<T>>& m_qMessagesIn;
            message<T> m_msgTemporaryIn;

            owner m_nOwnerType = owner::server;

            uint32_t id = 0;
    };
}

#endif /* !NYANET_CONNECTION_H_ */
