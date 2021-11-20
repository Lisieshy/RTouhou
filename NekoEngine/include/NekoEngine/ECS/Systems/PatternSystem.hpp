/*
** EPITECH PROJECT, 2021
** PatternSystem
** File description:
** PatternSystem
*/

/**
 * @file        PatternSystem.hpp
 * @brief       Physics System class
 * @details     ECS are fun, ECS are life.
 * @author      Eliott Ferry (@Gidorah)
 * @date        16/11/2021
 */

#ifndef PATTERNSYSTEM_HPP_
#define PATTERNSYSTEM_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class PatternSystem : public ne::System {
        public:
            void update(float& dt);
    };
}

#endif /* !PATTERNSYSTEM_HPP_ */