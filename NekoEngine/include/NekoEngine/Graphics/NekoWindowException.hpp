/*
** EPITECH PROJECT, 2021
** NekoWindowException
** File description:
** NekoWindowException
*/

/**
 * @file        NekoWindowException.hpp
 * @brief       WindowException handling class inheriting from NekoException.
 * @details     This class is supposed to be the one handling all of the ne::Window related exceptions. Supposed.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef NEKOWINDOWEXCEPTION_HPP_
#define NEKOWINDOWEXCEPTION_HPP_

#include "NekoEngine/NekoException/NekoException.hpp"

namespace ne {
    /**
     * @brief NekoEngine Window related exceptions.
     */
    class NekoWindowException : public NekoException {
        public:
            /**
             * @brief NekoWindowException constructor
             * 
             * @param what Message of the exception.
             * @param context Context of the exception. (Optional)
             */
            NekoWindowException(std::string const& what, std::string const& context);
    };
}

#endif /* !NEKOWINDOWEXCEPTION_HPP_ */
