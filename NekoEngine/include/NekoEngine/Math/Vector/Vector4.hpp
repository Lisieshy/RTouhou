/*
** EPITECH PROJECT, 2021
** Vector4
** File description:
** Vector4
*/

/**
 * @file        Vector4.hpp
 * @brief       Contains Vector4 template class.
 * @details     This template contains all the basic definitions of a 4D Vector.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR_HPP_
#ifndef VECTOR4_HPP_
#define VECTOR4_HPP_

namespace ne {
    /**
     * @brief Vector4 class taking <Type>.
     * 
     * @tparam Type Type of the Vector4 you want to create.
     */
    template<typename Type>
    class Vector4 {
        public:
            Vector4();
            Vector4(Type x, Type y, Type z, Type w);

            static Vector4<Type> Zero();
            static Vector4<Type> One();

            Type x;
            Type y;
            Type z;
            Type w;
    };

    template<typename Type>
    Vector4<Type>& operator -=(Vector4<Type>& left, const Vector4<Type>& right);

    template<typename Type>
    Vector4<Type>& operator +=(Vector4<Type>& left, const Vector4<Type>& right);

    template<typename Type>
    Vector4<Type> operator +(const Vector4<Type>& left, const Vector4<Type>& right);

    template<typename Type>
    Vector4<Type> operator -(const Vector4<Type>& left, const Vector4<Type>& right);

    template<typename Type>
    Vector4<Type> operator *(const Vector4<Type>& left, Type right);

    template<typename Type>
    Vector4<Type> operator *(Type left, const Vector4<Type>& right);

    template<typename Type>
    Vector4<Type>& operator *=(Vector4<Type>& left, Type right);

    template<typename Type>
    Vector4<Type> operator /(const Vector4<Type>& left, Type right);

    template<typename Type>
    Vector4<Type> operator /=(Vector4<Type>& left, Type right);

    template<typename Type>
    Vector4<Type> operator -(const Vector4<Type>& right);
}

#include "Vector4.tpp"

#endif
#endif /* !VECTOR4_HPP_ */
