/*
** EPITECH PROJECT, 2021
** RigidBody
** File description:
** RigidBody
*/

/**
 * @file        RigidBody.hpp
 * @brief       RigidBody component
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#ifndef RIGIDBODY2D_HPP_
#define RIGIDBODY2D_HPP_

#include "NekoEngine/Math/Vector/Vector.hpp"

namespace ne {
    class RigidBody {
        public:
            ne::Math::Vector3f velocity;
            ne::Math::Vector3f acceleration;
    };
}

#endif /* !RIGIDBODY_HPP_ */
