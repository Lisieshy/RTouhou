/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class Collision : public ne::System {
        public:
            void update();
    };
}

#endif /* !COLLISION_HPP_ */
