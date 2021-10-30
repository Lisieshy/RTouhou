/*
** EPITECH PROJECT, 2021
** NekoException
** File description:
** NekoException
*/

/**
 * @file        NekoException.cpp
 * @brief       Contains the NekoException implementation.
 * @details     Since it's a very basic implementation it's not really necessary but I like to keep my code clean.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#include "NekoEngine/NekoException/NekoException.hpp"

ne::NekoException::NekoException(std::string const& what, std::string const& context = "Not Defined.") : m_what(what), m_context(context) {}

const char* ne::NekoException::what() const noexcept
{
    return m_what.c_str();
}

const char* ne::NekoException::getContext() const noexcept
{
    return m_context.c_str();
}