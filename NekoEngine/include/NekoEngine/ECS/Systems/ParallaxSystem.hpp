/*
** EPITECH PROJECT, 2021
** ParallaxSystem.hpp
** File description:
** ParallaxSystem.hpp
*/

#ifndef PARALLAXSYSTEM_HPP
#define PARALLAXSYSTEM_HPP
#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class ParallaxSystem : public ne::System{
        public:
            void update(float dt);
    };
}
#endif /* !PARALLAXSYSTEM_HPP */
