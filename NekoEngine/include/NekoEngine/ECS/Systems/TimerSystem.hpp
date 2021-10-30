/*
** EPITECH PROJECT, 2021
** TimerSystem
** File description:
** TimerSystem
*/

/**
 * @file        TimerSystem.hpp
 * @brief       Controls System class
 * @details     ECS are fun, ECS are life.
 * @author      Gabriel Huguenin-Dumittan (@Autosuffisant)
 * @date        05/2021
 */

#ifndef TIMERSYSTEM_HPP_
#define TIMERSYSTEM_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class TimerSystem : public ne::System {
        public:
            void update();
    };
}

#endif /* !TIMERSYSTEM_HPP_ */