/*
** EPITECH PROJECT, 2021
** Scene
** File description:
** Scene
*/

/**
 * @file        Scene.cpp
 * @brief       For the love of god
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#include "NekoEngine/Scenes/Scene.hpp"
#include "NekoEngine/ECS/Systems/Systems.hpp"

ne::Scene::Scene() : coordinator(std::make_shared<ne::Coordinator>())
{
    coordinator->init();
}

