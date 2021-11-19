/*
** EPITECH PROJECT, 2021
** Color
** File description:
** Color
*/

/**
 * @file        Color.hpp
 * @brief       Color component
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <cstdint>

namespace ne {
    class Color {
        public:
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
    };
}

#endif /* !TRANSFORM_HPP_ */