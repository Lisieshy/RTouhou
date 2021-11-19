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
#include <cmath>

namespace ne {
ne::Math::Vector3f ne::Patterns::rightToLeftPattern()
{
    return(ne::Math::Vector3f{-60.f, 0.f, 0.f});
}

ne::Math::Vector3f ne::Patterns::leftToRightPattern()
{
    return(ne::Math::Vector3f{60.f, 0.f, 0.f});
}

ne::Math::Vector3f ne::Patterns::topToBotPattern()
{
    return(ne::Math::Vector3f{0.f, 60.f, 0.f});
}

ne::Math::Vector3f ne::Patterns::leftToRightCirclePattern()
{
    static double angle = 0;
    angle += 0.00001;
    float x = cos(angle) * 110 ;
    float y = sin(angle) * 90;
    x += 50;
    y += 0;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::rightToLeftCirclePattern()
{
    static double angle = 0;
    angle += 0.00001;
    float x = cos(angle) * 110;
    float y = sin(angle) * 90;
    x -= 50;
    y += 0;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::topToBotCirclePattern()
{
    static double angle = 0;
    angle += 0.00001;
    float x = cos(angle) * 110;
    float y = sin(angle) * 90;
    x += 0;
    y += 50;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::topToBotSnakePattern()
{
    int originX = 0;
    int originY = 80;
    static double angle = 0;
    angle += 0.00001;

    float x = originX + cos(angle) * 100;
    float y = originY + cos(angle) * 0;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::leftToRightSnakePattern()
{
    int originX = 90;
    int originY = 0;
    static double angle = 0;
    angle += 0.00004;

    float x = originX + cos(angle) * 0;
    float y = originY + cos(angle) * 110;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::rightToLeftSnakePattern()
{
    int originX = -90;
    int originY = 0;
    static double angle = 0;
    angle += 0.00004;

    float x = originX + cos(angle) * 0;
    float y = originY + cos(angle) * 110;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Math::Vector3f ne::Patterns::topToBotAndBackPattern()
{
    static double angle = 0;
    angle += 0.000004;

    float x = cos(angle) * 0;
    float y = cos(angle) * 80;

    return(ne::Math::Vector3f{x, y, 0.f});
}

ne::Patterns::~Patterns()
{

}
}
