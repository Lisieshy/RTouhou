/*
** EPITECH PROJECT, 2021
** Timer
** File description:
** Timer
*/

/**
 * @file        Timer.hpp
 * @brief       Timer component
 * @details     ECS are fun, ECS are life.
 * @author      Gabriel Huguenin-Dumittan (@Autosuffisant)
 * @date        05/2021
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

namespace ne {
    class Timer {
        public:
            Timer() = default;

            Timer(std::chrono::milliseconds endTime);

            ~Timer();

            /**
             * Time when the timer was started
             */
            std::chrono::time_point<std::chrono::system_clock> startTime;

            /**
             * Time in milliseconds after which the timer should stop
             */
            std::chrono::milliseconds endTime;

            /**
             * Tells if the timer has started
             */
            bool started = true;
    };
}

#endif /* !TIMER_HPP_ */
