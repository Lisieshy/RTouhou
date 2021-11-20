/*
** EPITECH PROJECT, 2021
** Background.hpp
** File description:
** Background.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

namespace ne {
    class Background {
        public:
            Background();
            ~Background();
            ne::Skin& getSkin();

            ne::Skin skin;
    };
}

#endif /* !BACKGROUND_HPP */
