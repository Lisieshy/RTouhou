/*
** EPITECH PROJECT, 2021
** NekoException
** File description:
** NekoException
*/

/**
 * @file        NekoException.hpp
 * @brief       Contains the NekoEngine main exception type.
 * @details     This exception type inherits from std::exception and should be inherited by all subexceptions in NekoEngine.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef NEKOEXCEPTION_HPP_
#define NEKOEXCEPTION_HPP_

#include <string>

namespace ne {
    /**
     * @brief NekoEngine main exception type.
     */
    class NekoException : public std::exception {
        public:
            /**
             * @brief NekoException constructor
             * 
             * @param what Message of the exception.
             * @param context Context of the exception. (Optional)
             */
            NekoException(std::string const& what, std::string const& context);

            /**
             * @brief Gets the Message of the exception
             * 
             * @return const char* 
             */
            const char* what() const noexcept;

            /**
             * @brief Gets the Context of the exception
             * 
             * @return const char* 
             */
            const char* getContext() const noexcept;
        private:
            std::string m_what;
            std::string m_context;
    };
}

#endif /* !NEKOEXCEPTION_HPP_ */
