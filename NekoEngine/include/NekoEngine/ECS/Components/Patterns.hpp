/*
** EPITECH PROJECT, 2021
** Patterns
** File description:
** Patterns
*/

/**
 * @file        Patterns.hpp
 * @brief       Patterns component
 * @details     ECS are fun, ECS are life.
 * @author      Eliott ferry (@Gidorah)
 * @date        16/11/2021
 */

#ifndef PATTERNS_HPP_
#define PATTERNS_HPP_

#include "NekoEngine/Math/Vector/Vector.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"

namespace ne {
    enum PatternType {
        SINUSOIDAL,
    };
    class Patterns {
        public:
            Patterns() = default;

            ~Patterns();

            void updatePos(ne::Transform &, float);
    };
}

#endif /* !PATTERNS_HPP_ */
