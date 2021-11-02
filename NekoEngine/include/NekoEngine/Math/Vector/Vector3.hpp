/*
** EPITECH PROJECT, 2021
** Vector3
** File description:
** Vector3
*/

/**
 * @file        Vector3.hpp
 * @brief       Contains Vector3 template class.
 * @details     This template contains all the basic definitions of a 3D Vector.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifdef VECTOR_HPP_
#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

/**
 * @namespace ne::Math
 */
namespace ne::Math {
    /**
     * @brief Vector3 class taking <Type>.
     * 
     * @tparam Type Type of the Vector3 you want to create.
     */
    template<typename Type>
    class Vector3 {
        public:
            Vector3();
            Vector3(Type x, Type y, Type z);

            static Vector3<Type> Zero();
            static Vector3<Type> One();

            Type x;
            Type y;
            Type z;
    };

    template<typename Type>
    Vector3<Type>& operator -=(Vector3<Type>& left, const Vector3<Type>& right);

    template<typename Type>
    Vector3<Type>& operator +=(Vector3<Type>& left, const Vector3<Type>& right);

    template<typename Type>
    Vector3<Type> operator +(const Vector3<Type>& left, const Vector3<Type>& right);

    template<typename Type>
    Vector3<Type> operator -(const Vector3<Type>& left, const Vector3<Type>& right);

    template<typename Type>
    Vector3<Type> operator *(const Vector3<Type>& left, Type right);

    template<typename Type>
    Vector3<Type> operator *(Type left, const Vector3<Type>& right);

    template<typename Type>
    Vector3<Type>& operator *=(Vector3<Type>& left, Type right);

    template<typename Type>
    Vector3<Type> operator /(const Vector3<Type>& left, Type right);

    template<typename Type>
    Vector3<Type> operator /=(Vector3<Type>& left, Type right);

    template<typename Type>
    Vector3<Type> operator -(const Vector3<Type>& right);
}

#include "Vector3.tpp"

#endif
#endif /* !VECTOR3_HPP_ */