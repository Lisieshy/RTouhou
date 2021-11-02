/*
** EPITECH PROJECT, 2021
** Vector2
** File description:
** Vector2 template implementations
*/

/**
 * @file        Vector2.tpp
 * @brief       Contains Vector2 template class implementation.
 * @details     This file contains all the basic implementations of the Vector2 template.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR2_HPP_
#ifndef VECTOR2_TPP_
#define VECTOR2_TPP_

#include "Vector2.hpp"

template<typename Type>
ne::Math::Vector2<Type>::Vector2() : x(0), y(0) {}

template<typename Type>
ne::Math::Vector2<Type>::Vector2(Type x, Type y) : x(x), y(y) {}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::Vector2<Type>::Zero()
{
    ne::Math::Vector2<Type> vect(static_cast<Type>(0), static_cast<Type>(0));
    return vect;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::Vector2<Type>::One()
{
    ne::Math::Vector2<Type> vect(static_cast<Type>(1), static_cast<Type>(1));
    return vect;
}

template<typename Type>
ne::Math::Vector2<Type>& ne::Math::operator -=(Vector2<Type>& lhs, const Vector2<Type>& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;

    return lhs;
}

template<typename Type>
ne::Math::Vector2<Type>& ne::Math::operator +=(Vector2<Type>& lhs, const Vector2<Type>& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;

    return lhs;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator +(const Vector2<Type>& lhs, const Vector2<Type>& rhs)
{
    ne::Math::Vector2<Type> vect(lhs.x + rhs.x, lhs.y + rhs.y);

    return vect;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator -(const Vector2<Type>& lhs, const Vector2<Type>& rhs)
{
    ne::Math::Vector2<Type> vect(lhs.x - rhs.x, lhs.y - rhs.y);

    return vect;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator *(const Vector2<Type>& lhs, Type rhs)
{
    ne::Math::Vector2<Type> vect(lhs.x * rhs, lhs.y * rhs);

    return vect;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator *(Type lhs, const Vector2<Type>& rhs)
{
    ne::Math::Vector2<Type> vect(lhs * rhs.x, lhs * rhs.y);

    return vect;
}

template<typename Type>
ne::Math::Vector2<Type>& ne::Math::operator *=(Vector2<Type>& lhs, Type rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;

    return lhs;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator /(const Vector2<Type>& lhs, Type rhs)
{
    ne::Math::Vector2<Type> vect(lhs.x / rhs, lhs.y / rhs);

    return vect;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator /=(Vector2<Type>& lhs, Type rhs)
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;

    return lhs;
}

template<typename Type>
ne::Math::Vector2<Type> ne::Math::operator -(const Vector2<Type>& rhs)
{
    ne::Math::Vector2<Type> vect(-rhs.x, -rhs.y);

    return vect;
}

#endif
#endif