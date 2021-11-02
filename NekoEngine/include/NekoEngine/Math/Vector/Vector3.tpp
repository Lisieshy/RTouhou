/*
** EPITECH PROJECT, 2021
** Vector3
** File description:
** Vector3 template implementations
*/

/**
 * @file        Vector3.tpp
 * @brief       Contains Vector3 template class implementation.
 * @details     This file contains all the basic implementations of the Vector3 template.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR3_HPP_
#ifndef VECTOR3_TPP_
#define VECTOR3_TPP_

#include "Vector3.hpp"

template<typename Type>
ne::Math::Vector3<Type>::Vector3() : x(0), y(0), z(0) {}

template<typename Type>
ne::Math::Vector3<Type>::Vector3(Type x, Type y, Type z) : x(x), y(y), z(z) {}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::Vector3<Type>::Zero()
{
    ne::Math::Vector3<Type> vect(static_cast<Type>(0), static_cast<Type>(0), static_cast<Type>(0));
    return vect;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::Vector3<Type>::One()
{
    ne::Math::Vector3<Type> vect(static_cast<Type>(1), static_cast<Type>(1), static_cast<Type>(1));
    return vect;
}

template<typename Type>
ne::Math::Vector3<Type>& ne::Math::operator -=(Vector3<Type>& lhs, const Vector3<Type>& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;

    return lhs;
}

template<typename Type>
ne::Math::Vector3<Type>& ne::Math::operator +=(Vector3<Type>& lhs, const Vector3<Type>& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;

    return lhs;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator +(const Vector3<Type>& lhs, const Vector3<Type>& rhs)
{
    ne::Math::Vector3<Type> vect(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);

    return vect;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator -(const Vector3<Type>& lhs, const Vector3<Type>& rhs)
{
    ne::Math::Vector3<Type> vect(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);

    return vect;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator *(const Vector3<Type>& lhs, Type rhs)
{
    ne::Math::Vector3<Type> vect(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);

    return vect;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator *(Type lhs, const Vector3<Type>& rhs)
{
    ne::Math::Vector3<Type> vect(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);

    return vect;
}

template<typename Type>
ne::Math::Vector3<Type>& ne::Math::operator *=(Vector3<Type>& lhs, Type rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;

    return lhs;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator /(const Vector3<Type>& lhs, Type rhs)
{
    ne::Math::Vector3<Type> vect(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);

    return vect;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator /=(Vector3<Type>& lhs, Type rhs)
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;

    return lhs;
}

template<typename Type>
ne::Math::Vector3<Type> ne::Math::operator -(const Vector3<Type>& rhs)
{
    ne::Math::Vector3<Type> vect(-rhs.x, -rhs.y, -rhs.z);

    return vect;
}

#endif
#endif