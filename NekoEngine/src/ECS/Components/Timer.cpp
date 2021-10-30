/*
** EPITECH PROJECT, 2021
** Timer
** File description:
** Timer
*/

/**
 * @file        Timer.cpp
 * @brief       Timer implementation.
 * @details     Implementation of the Timer class.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        10/2021
 */

#include "NekoEngine/ECS/Types.hpp"
#include "NekoEngine/ECS/Components/Timer.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"
#include <filesystem>

namespace ne {
    ne::Timer::Timer(std::chrono::milliseconds endTime) : endTime(endTime)
    {
        this->startTime = std::chrono::system_clock::now();
    }

    ne::Timer::~Timer()
    {
    }
}
