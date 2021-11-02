/*
** EPITECH PROJECT, 2021
** Matrix
** File description:
** Matrix template implementations
*/

/**
 * @file        Matrix.tpp
 * @brief       Contains Matrix template class implementation.
 * @details     This file contains all the basic implementations of the Matrix template.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        06/2021
 */

#ifdef MATRIX_HPP_
#ifndef MATRIX_TPP_
#define MATRIX_TPP_

#include "Matrix.hpp"

template<typename Type>
ne::Math::Matrix<Type>::Matrix() : 
    col1(ne::Math::Vector4<Type>()),
    col2(ne::Math::Vector4<Type>()),
    col3(ne::Math::Vector4<Type>()),
    col4(ne::Math::Vector4<Type>())
{
}

template<typename Type>
ne::Math::Matrix<Type>::Matrix(
    ne::Math::Vector4<Type> col1,
    ne::Math::Vector4<Type> col2,
    ne::Math::Vector4<Type> col3,
    ne::Math::Vector4<Type> col4)
    :
    col1(col1),
    col2(col2),
    col3(col3),
    col4(col4)
{
}

#endif
#endif