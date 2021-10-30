/*
** EPITECH PROJECT, 2021
** Color
** File description:
** Color
*/

/**
 * @file        Color.hpp
 * @brief       Color class
 * @details     Class holding color data, ie RGBA values as unsigned chars to constrain the range of values to 0-255.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef NEKO_GRAPHICAL_COLOR_HPP
#define NEKO_GRAPHICAL_COLOR_HPP

namespace ne {
    class Color {
        public:
            unsigned char r;        // Color red value
            unsigned char g;        // Color green value
            unsigned char b;        // Color blue value
            unsigned char a;        // Color alpha value
    };
}

#endif /* !NEKO_GRAPHICAL_COLOR_HPP */
