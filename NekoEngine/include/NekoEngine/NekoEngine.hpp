/*
** EPITECH PROJECT, 2021
** NekoEngine
** File description:
** NekoEngine
*/

/**
 * @file        NekoEngine.cpp
 * @brief       Contains all the NekoEngine .hpp files necessary to work flawlessly.
 * @details     All the .hpp files necessary to use the NekoEngine are included in here.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef NEKOENGINE_HPP_
#define NEKOENGINE_HPP_

// NekoExceptions include
#include "NekoEngine/NekoException/NekoException.hpp"
#include "NekoEngine/Graphics/NekoWindowException.hpp"

// NekoMaths includes
#include "NekoEngine/Math/Vector/Vector.hpp"
#include "NekoEngine/Math/Quaternion/Quaternion.hpp"
#include "NekoEngine/Math/Matrix/Matrix.hpp"

// NekoECS includes
#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/Scenes/Scene.hpp"

// NekoECS Components and systems includes
#include "NekoEngine/ECS/Components/Components.hpp"
#include "NekoEngine/ECS/Systems/Systems.hpp"

// NekoGraphics include
#include "NekoEngine/Graphics/Window.hpp"

#endif /* !NEKOENGINE_HPP_ */
