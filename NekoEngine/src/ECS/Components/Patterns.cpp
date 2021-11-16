/*
** EPITECH PROJECT, 2021
** Patterns
** File description:
** Patterns
*/

/**
 * @file        Patterns.cpp
 * @brief       Patterns implementation.
 * @details     Implementation of the Patterns class.
 * @author      Eliott Ferry (@Gidorah)
 * @date        16/2021
 */

#include "NekoEngine/ECS/Components/Patterns.hpp"
#include "NekoEngine/Math/Vector/Vector.hpp"
#include "NekoEngine/NekoException/NekoException.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include <filesystem>
#include <iostream>

namespace ne {
    // ne::Patterns::Patterns()
    // {

    // }

    void ne::Patterns::updatePos(ne::Transform &pos, float dt)
    {
        pos.position.x -= 10 * dt;
        // pos.y -= 10 * dt;
    }

    ne::Patterns::~Patterns()
    {

    }
}
