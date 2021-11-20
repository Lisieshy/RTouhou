/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** AnimationSystem
*/

#ifndef ANIMATIONSYSTEM_HPP_
#define ANIMATIONSYSTEM_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class AnimationSystem : public ne::System {
        public:
            void update(float& dt);

            float animationTime = 0.5f;
    };
}

#endif /* !ANIMATIONSYSTEM_HPP_ */
