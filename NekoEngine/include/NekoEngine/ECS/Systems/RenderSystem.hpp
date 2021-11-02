/*
** EPITECH PROJECT, 2021
** TimerSystem
** File description:
** TimerSystem
*/

/**
 * @file        RenderSystem.hpp
 * @brief       Render System class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        02/11/2021
 */

#ifndef RENDERSYSTEM_HPP_
#define RENDERSYSTEM_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class RenderSystem : public ne::System {
        public:
            void update();
    };
}

#endif /* !RENDERSYSTEM_HPP_ */