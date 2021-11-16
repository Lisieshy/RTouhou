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
#include <functional>

namespace ne {
    enum PatternType {
        SINUSOIDAL,
    };
    class Patterns {
        public:

            Patterns() = default;

            ~Patterns();

            ne::Math::Vector3f rightToLeftPattern();
            ne::Math::Vector3f leftToRightPattern();
            std::function<ne::Math::Vector3f()> patternFunc;
    };
}

#endif /* !PATTERNS_HPP_ */
