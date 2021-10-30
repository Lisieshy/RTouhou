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
            Vector3f position;
            Vector3f rotation;
            Vector3f scale;
    };
}

#endif /* !TRANSFORM_HPP_ */
