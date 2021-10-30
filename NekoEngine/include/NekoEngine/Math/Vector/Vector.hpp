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

using ne::operator -=;
using ne::operator +=;
using ne::operator -;
using ne::operator +;
using ne::operator *;
using ne::operator *=;
using ne::operator /;
using ne::operator /=;

namespace ne {
    using Vector2i = ne::Vector2<int>;
    using Vector2u = ne::Vector2<unsigned int>;
    using Vector2f = ne::Vector2<float>;
    using Vector3i = ne::Vector3<int>;
    using Vector3u = ne::Vector3<unsigned int>;
    using Vector3f = ne::Vector3<float>;
    using Vector4i = ne::Vector4<int>;
    using Vector4u = ne::Vector4<unsigned int>;
    using Vector4f = ne::Vector4<float>;
}
#endif /* !VECTOR_HPP_ */
