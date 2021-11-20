/*
** EPITECH PROJECT, 2021
** TextSystem.hpp
** File description:
** TextSystem.hpp
*/

#ifndef TEXTSYSTEM_HPP
#define TEXTSYSTEM_HPP
#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class TextSystem : public ne::System {
        public:
            void update();
    };
}

#endif /* !TEXTSYSTEM_HPP */
