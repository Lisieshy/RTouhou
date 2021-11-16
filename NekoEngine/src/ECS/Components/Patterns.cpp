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
    ne::Math::Vector3f ne::Patterns::rightToLeftPattern()
    {
        return(ne::Math::Vector3f{-10.f, 0.f, 0.f});
    }
    ne::Math::Vector3f ne::Patterns::leftToRightPattern()
    {
        return(ne::Math::Vector3f{10.f, 0.f, 0.f});
    }

    ne::Patterns::~Patterns()
    {

    }
}
