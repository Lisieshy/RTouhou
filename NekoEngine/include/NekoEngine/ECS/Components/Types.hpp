/*
** EPITECH PROJECT, 2021
** Types
** File description:
** Types
*/

/**
 * @file        Types.hpp
 * @brief       Types component
 * @details     ECS are fun, ECS are life.
 * @author      Eliott Ferry (@Gidorah)
 * @date        15/2021
 */

#include <SFML/Graphics.hpp>
#ifndef TYPES_HPP_
#define TYPES_HPP_

namespace ne {
    enum EntityType {
        PLAYER,
        BULLET,
        ENEMYT1,
        ENEMYT2,
        ENEMYT3,
        ENEMYT4,
        ENEMYT5,
    };
    class Type {
        public:
            EntityType type;
    };
}

#endif /* !TYPES_HPP_ */
