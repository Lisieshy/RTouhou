/*
** EPITECH PROJECT, 2021
** PhysicsSystem
** File description:
** PhysicsSystem
*/

/**
 * @file        PhysicsSystem.hpp
 * @brief       Physics System class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#ifndef PHYSICSSYSTEM_HPP_
#define PHYSICSSYSTEM_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class PhysicsSystem : public ne::System {
        public:
            void update(float dt);
    };
}

#endif /* !PHYSICSSYSTEM_HPP_ */