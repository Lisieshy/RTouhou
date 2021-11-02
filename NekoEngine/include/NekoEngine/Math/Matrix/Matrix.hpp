/*
** EPITECH PROJECT, 2021
** Matrix
** File description:
** Matrix
*/

/**
 * @file        Matrix.hpp
 * @brief       Contains Matrix template class.
 * @details     This template contains all the basic definitions of a 4x4 Matrix.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        06/2021
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include "NekoEngine/Math/Vector/Vector.hpp"

/**
 * @namespace ne::Math
 */
namespace ne::Math {
    /**
     * @brief Matrix class taking <Type>.
     * 
     * @tparam Type Type of the Matrix you want to create.
     */
    template<typename Type>
    class Matrix {
        public:
            Matrix();
            Matrix(
                ne::Math::Vector4<Type> col1,
                ne::Math::Vector4<Type> col2,
                ne::Math::Vector4<Type> col3,
                ne::Math::Vector4<Type> col4
            );

            ne::Math::Vector4<Type> col1;
            ne::Math::Vector4<Type> col2;
            ne::Math::Vector4<Type> col3;
            ne::Math::Vector4<Type> col4;
    };
}

#include "Matrix.tpp"

#endif /* !VECTOR2_HPP_ */