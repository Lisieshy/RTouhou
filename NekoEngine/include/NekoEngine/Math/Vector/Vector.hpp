/*
** EPITECH PROJECT, 2021
** Vector
** File description:
** Vector
*/

/**
 * @file        Vector.hpp
 * @brief       Contains all headers for all Vector types.
 * @details     Just here to simplify the usage of Vector types by a lot. It helps. Trust me.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

using ne::Math::operator -=;
using ne::Math::operator +=;
using ne::Math::operator -;
using ne::Math::operator +;
using ne::Math::operator *;
using ne::Math::operator *=;
using ne::Math::operator /;
using ne::Math::operator /=;

/**
 * @namespace ne::Math
 */
namespace ne::Math {
    using Vector2i = ne::Math::Vector2<int>;
    using Vector2u = ne::Math::Vector2<unsigned int>;
    using Vector2f = ne::Math::Vector2<float>;
    using Vector3i = ne::Math::Vector3<int>;
    using Vector3u = ne::Math::Vector3<unsigned int>;
    using Vector3f = ne::Math::Vector3<float>;
    using Vector4i = ne::Math::Vector4<int>;
    using Vector4u = ne::Math::Vector4<unsigned int>;
    using Vector4f = ne::Math::Vector4<float>;
}
#endif /* !VECTOR_HPP_ */
