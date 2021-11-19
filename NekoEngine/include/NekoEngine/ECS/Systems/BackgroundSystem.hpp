/*
** EPITECH PROJECT, 2021
** BackgroundSystem.hpp
** File description:
** BackgroundSystem.hpp
*/

#ifndef BACKGROUNDSYSTEM_HPP
#define BACKGROUNDSYSTEM_HPP
#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class BackgroundSystem : public ne::System {
        public:
            void update();
    };
}
#endif /* !BACKGROUNDSYSTEM_HPP */
