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
    
    template <typename T>
    class IServer;

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

                if (m_nOwnerType == owner::server) {
                    m_nHandshakeOut = uint64_t(std::chrono::system_clock::now().time_since_epoch().count());

                    m_nHandshakeCheck = scramble(m_nHandshakeOut);
                }
                else {
                    m_nHandshakeIn = 0;
                    m_nHandshakeOut = 0;

                }
            }

            virtual ~connection()
            {

            }
            /**
             * @brief Connect a Server to a Client
             * 
             * @param nn::IServer<T>* 
             * @param uint32_t 
             */
            auto ConnectToClient(
                nn::IServer<T>* server,
                uint32_t uid = 0
            ) -> void
            {
                if (m_nOwnerType == owner::server) {
                    if (m_socket.is_open()) {
                        id = uid;
                        WriteValidation();
                        ReadValidation(server);
                        // ReadHeader();
                    }
                }
            }
            /**
             * @brief Connect a Client to a Server
             * 
             * @param const asio::ip::tcp::resolver::results_type& 
             */
            auto ConnectToServer(
                const asio::ip::tcp::resolver::results_type& endpoints
            ) -> void
            {
                if (m_nOwnerType == owner::client) {
                    asio::async_connect(
                        m_socket,
                        endpoints,
                        [this](
                            std::error_code ec,
                            asio::ip::tcp::endpoint endpoint
                        ) {
                            if (!ec) {
                                ReadValidation();
                                // ReadHeader();
                            }
                        }
                    );
                }
            }
            /**
             * @brief Close the connection socket
             * 
             */
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
            /**
             * @brief Is there a connection
             * 
             * @return bool
             */
            auto IsConnected(
            ) -> bool const
            {
                return m_socket.is_open();
            }
            /**
             * @brief Send a message
             * 
             * @param const message<T>& 
             */
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
            /**
             * @brief Get the ID of the connection.
             * 
             * @return uint32_t const 
             */
            auto GetID(
            ) -> uint32_t const
            {
                return id;
            }

        private:
            /**
             * @brief Read the header of the message
             * 
             */
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
            /**
             * @brief Read the body of the message
             * 
             */
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
            /**
             * @brief Write the header of the message
             * 
             */
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
            /**
             * @brief Write the body of the message
             * 
             */
            auto WriteBody(
            ) -> void
            {
                asio::async_write(
                    m_socket,
                    asio::buffer(
                        m_qMessagesOut.front().body.data(),
                        m_qMessagesOut.front().body.size()
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
            /**
             * @brief Storing incoming message in a queue of message
             * 
             */
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
            /**
             * @brief Scramble an input to be sure this is a known Client
             * 
             * @param uint64_t 
             * @return uint64_t 
             */
            uint64_t scramble(uint64_t nInput)
            {
                uint64_t out = nInput ^ 0xDEADBEEFC0DECAFE;
                out = (out & 0xF0F0F0F0F0F0F0) >> 4 | (out & 0x0F0F0F0F0F0F0F) << 4;
                return out ^ 0xC0DEFACE12345678;
            }
            /**
             * @brief Write Validation
             * 
             */
            auto WriteValidation(
            ) -> void
            {
                asio::async_write(m_socket, asio::buffer(&m_nHandshakeOut, sizeof(uint64_t)),
                [this](std::error_code ec, std::size_t length)
                {
                    if (!ec) {
                        if (m_nOwnerType == owner::client)
                            ReadHeader();
                    }
                    else {
                        m_socket.close();
                    }
                });
            }
            /**
             * @brief Read the validation sended from the Client
             * 
             * @param nn::IServer<T>* 
             */
            auto ReadValidation(
                nn::IServer<T>* server = nullptr
            ) -> void
            {
                asio::async_read(m_socket, asio::buffer(&m_nHandshakeIn, sizeof(uint64_t)),
                [this, server](std::error_code ec, std::size_t length)
                {
                    if (!ec) {
                        if (m_nOwnerType == owner::server) {
                            if (m_nHandshakeIn == m_nHandshakeCheck) {
                                nl::nyalog(nl::LogLevel::Info, "Client Validated");
                                server->OnClientValidated(this->shared_from_this());

                                ReadHeader();
                            }
                            else {
                                nl::nyalog(nl::LogLevel::Info, "Client didn't passed validation test");
                                m_socket.close();
                            }
                        }
                        else {
                            m_nHandshakeOut = scramble(m_nHandshakeIn);

                            WriteValidation();
                        }
                    }
                    else {
                        nl::nyalog(nl::LogLevel::Info, "Client Disconnected in ReadValidation");
                        m_socket.close();
                    }
                });
            }
        protected:
            asio::ip::tcp::socket m_socket;

            asio::io_context& m_asioContext;

            tsqueue<message<T>> m_qMessagesOut;

            tsqueue<owned_message<T>>& m_qMessagesIn;
            message<T> m_msgTemporaryIn;

            owner m_nOwnerType = owner::server;

            uint32_t id = 0;

            uint64_t m_nHandshakeOut = 0;
            uint64_t m_nHandshakeIn = 0;
            uint64_t m_nHandshakeCheck = 0;
    };
}

#endif /* !NYANET_CONNECTION_H_ */
