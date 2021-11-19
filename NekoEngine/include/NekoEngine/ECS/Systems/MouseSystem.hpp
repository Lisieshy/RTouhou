/*
** EPITECH PROJECT, 2021
** MouseSystem.hpp
** File description:
** MouseSystem.hpp
*/

/**
 * @file    MouseSystem.hpp
 * @brief   Mouse System class
 * @details ECS are fun, ECS are life.
 * @author  Pierre Fricker (@Exy-tek)
 * @date    17/11/2021
 */

#ifndef MOUSESYSTEM_HPP
#define MOUSESYSTEM_HPP

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class MouseSystem : public ne::System {
        public:
            void update();
    };
}

#endif /* !MOUSESYSTEM_HPP */
