/*
** EPITECH PROJECT, 2021
** Scene
** File description:
** Scene
*/

/**
 * @file        Scene.hpp
 * @brief       Scene class.
 * @details     Scene class holding holding and constructing it's own coordinator.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */


#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "NekoEngine/ECS/Coordinator.hpp"

namespace ne {
    class Scene {
        public:
            Scene();

            std::shared_ptr<ne::Coordinator> coordinator;
    };
}

#endif /* !SCENE_HPP_ */
