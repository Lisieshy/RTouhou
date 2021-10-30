/*
** EPITECH PROJECT, 2021
** NekoWindowException
** File description:
** NekoWindowException
*/

/**
 * @file        NekoWindowException.cpp
 * @brief       Contains NekoWindowException.hpp constructor implementation.
 * @details     Extremely simple implementation, but it does the trick!
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#include "NekoEngine/Graphics/NekoWindowException.hpp"

ne::NekoWindowException::NekoWindowException(std::string const& what, std::string const& context = "ne::Window related error.") : ne::NekoException(what, context) {}
