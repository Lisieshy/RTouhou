/*
** EPITECH PROJECT, 2021
** Transform
** File description:
** Transform
*/

/**
 * @file        Transform.hpp
 * @brief       Transform component
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "NekoEngine/Math/Vector/Vector.hpp"

namespace ne {
    class Transform {
        public:
            ne::Math::Vector3f position;
            ne::Math::Vector3f rotation;
            ne::Math::Vector3f scale;
    };
}

#endif /* !TRANSFORM_HPP_ */
