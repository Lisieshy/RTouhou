/*
** EPITECH PROJECT, 2021
** Vector4
** File description:
** Vector4 template implementations
*/

/**
 * @file        Vector4.tpp
 * @brief       Contains Vector4 template class implementation.
 * @details     This file contains all the basic implementations of the Vector4 template.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR4_HPP_
#ifndef VECTOR4_TPP_
#define VECTOR4_TPP_

#include "Vector4.hpp"

template<typename Type>
ne::Vector4<Type>::Vector4() : x(0), y(0), z(0), w(0) {}

template<typename Type>
ne::Vector4<Type>::Vector4(Type x, Type y, Type z, Type w) : x(x), y(y), z(z), w(w) {}

template<typename Type>
ne::Vector4<Type> ne::Vector4<Type>::Zero()
{
    ne::Vector4<Type> vect(static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0));
    return vect;
}

template<typename Type>
ne::Vector4<Type> ne::Vector4<Type>::One()
{
    ne::Vector4<Type> vect(static_cast<Type>(1), static_cast<Type>(1), static_cast<Type>(1), static_cast<Type>(1));
    return vect;
}

template<typename Type>
ne::Vector4<Type>& ne::operator -=(Vector4<Type>& lhs, const Vector4<Type>& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;

    return lhs;
}

template<typename Type>
ne::Vector4<Type>& ne::operator +=(Vector4<Type>& lhs, const Vector4<Type>& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;

    return lhs;
}

template<typename Type>
ne::Vector4<Type> ne::operator +(const Vector4<Type>& lhs, const Vector4<Type>& rhs)
{
    ne::Vector4<Type> vect(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);

    return vect;
}

template<typename Type>
ne::Vector4<Type> ne::operator -(const Vector4<Type>& lhs, const Vector4<Type>& rhs)
{
    ne::Vector4<Type> vect(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);

    return vect;
}

template<typename Type>
ne::Vector4<Type> ne::operator *(const Vector4<Type>& lhs, Type rhs)
{
    ne::Vector4<Type> vect(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);

    return vect;
}

template<typename Type>
ne::Vector4<Type> ne::operator *(Type lhs, const Vector4<Type>& rhs)
{
    ne::Vector4<Type> vect(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);

    return vect;
}

template<typename Type>
ne::Vector4<Type>& ne::operator *=(Vector4<Type>& lhs, Type rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;

    return lhs;
}

template<typename Type>
ne::Vector4<Type> ne::operator /(const Vector4<Type>& lhs, Type rhs)
{
    ne::Vector4<Type> vect(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);

    return vect;
}

template<typename Type>
ne::Vector4<Type> ne::operator /=(Vector4<Type>& lhs, Type rhs)
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    lhs.w /= rhs.w;

    return lhs;
}

template<typename Type>
ne::Vector4<Type> ne::operator -(const Vector4<Type>& rhs)
{
    ne::Vector4<Type> vect(-rhs.x, -rhs.y, -rhs.z, -rhs.w);

    return vect;
}

#endif
#endif