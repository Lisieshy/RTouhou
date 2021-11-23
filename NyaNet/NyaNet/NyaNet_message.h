/*
** EPITECH PROJECT, 2021
** NyaNet_message
** File description:
** NyaNet_message
*/

#ifndef NYANET_MESSAGE_H_
#define NYANET_MESSAGE_H_

#include "NyaNet_common.h"

namespace nn {
    template <typename T>
    struct message_header {
        T id{};
        uint32_t size = 0;
    };

    template <typename T>
    struct message {
        message_header<T> header{};
        std::vector<uint8_t> body;

        /**
         * @brief Size of the message
         * 
         * @return size_t const 
         */
        auto size(
        ) -> size_t const
        {
            return body.size();
        }
        auto friend operator<<(
            std::ostream& os,
            const message<T>& msg
        ) -> std::ostream&
        {
            os << "ID:" << int(msg.header.id) << " Size:" << msg.header.size;
            return os;
        }
        /**
         * @brief Append data to the message
         * 
         * @tparam Type 
         * @param message<T>& 
         * @param const Type& 
         * @return message<T>& 
         */
        template<typename Type>
        auto friend operator<<(
            message<T>& msg,
            const Type& data
        ) -> message<T>&
        {
            static_assert(
                std::is_standard_layout<Type>::value,
                "Data is too complex to be used."
            );

            size_t i = msg.body.size();

            msg.body.resize(
                msg.body.size() + sizeof(Type)
            );

            std::memcpy(
                msg.body.data() + i,
                &data,
                sizeof(Type)
            );

            msg.header.size = msg.size();

            return msg;
        }


        template<typename Type>
        /**
         * @brief Export the data from the message
         * 
         * @param message<T>& 
         * @param Type& 
         * @return message<T>& 
         */
        auto friend operator>>(
            message<T>& msg,
            Type& data
        ) -> message<T>&
        {
            static_assert(
                std::is_standard_layout<Type>::value,
                "Data is too complex to be used."
            );

            size_t i = msg.body.size() - sizeof(Type);

            std::memcpy(
                &data,
                msg.body.data() + i,
                sizeof(Type)
            );

            msg.body.resize(i);

            msg.header.size = msg.size();

            return msg;
        }
    };

    template<typename T>
    class connection;

    template<typename T>
    struct owned_message
    {
        std::shared_ptr<connection<T>> remote = nullptr;
        message<T> msg;

        auto friend operator<<(
            std::ostream& os,
            const owned_message<T>& msg
        ) -> std::ostream&
        {
            os << msg.msg;
            return os;
        }
    };
}

#endif /* !NYANET_MESSAGE_H_ */
