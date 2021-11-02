/*
** EPITECH PROJECT, 2021
** Gravity
** File description:
** Gravity
*/

/**
 * @file        Gravity.hpp
 * @brief       Gravity component
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#ifndef GRAVITY_HPP_
#define GRAVITY_HPP_

#include "NekoEngine/Math/Vector/Vector.hpp"


namespace ne {
    class Gravity {
        public:
            ne::Math::Vector3f force;
    };
}

#endif /* !GRAVITY_HPP_ */
