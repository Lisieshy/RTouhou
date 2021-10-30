/*
** EPITECH PROJECT, 2021
** Vector2
** File description:
** Vector2
*/

/**
 * @file        Vector2.hpp
 * @brief       Contains Vector2 template class.
 * @details     This template contains all the basic definitions of a 2D Vector.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR_HPP_
#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

namespace ne {
    /**
     * @brief Vector2 class taking <Type>.
     * 
     * @tparam Type Type of the Vector2 you want to create.
     */
    template<typename Type>
    class Vector2 {
        public:
            Vector2();
            Vector2(Type x, Type y);

            static Vector2<Type> Zero();
            static Vector2<Type> One();

            Type x;
            Type y;
    };

    template<typename Type>
    Vector2<Type>& operator -=(Vector2<Type>& left, const Vector2<Type>& right);

    template<typename Type>
    Vector2<Type>& operator +=(Vector2<Type>& left, const Vector2<Type>& right);

    template<typename Type>
    Vector2<Type> operator +(const Vector2<Type>& left, const Vector2<Type>& right);

    template<typename Type>
    Vector2<Type> operator -(const Vector2<Type>& left, const Vector2<Type>& right);

    template<typename Type>
    Vector2<Type> operator *(const Vector2<Type>& left, Type right);

    template<typename Type>
    Vector2<Type> operator *(Type left, const Vector2<Type>& right);

    template<typename Type>
    Vector2<Type>& operator *=(Vector2<Type>& left, Type right);

    template<typename Type>
    Vector2<Type> operator /(const Vector2<Type>& left, Type right);

    template<typename Type>
    Vector2<Type> operator /=(Vector2<Type>& left, Type right);

    template<typename Type>
    Vector2<Type> operator -(const Vector2<Type>& right);
}

#include "Vector2.tpp"

#endif
#endif /* !VECTOR2_HPP_ */