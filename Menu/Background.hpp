/*
** EPITECH PROJECT, 2021
** Background.hpp
** File description:
** Background.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

/**
 * @namespace ne
 */
namespace ne {
    /**
     * @brief class Background
     * @class Background
     */
    class Background {
        public:
            /**
             * @brief Construct a new Background object
             */
            Background();
            /**
             * @brief Destroy the Background object
             */
            ~Background();

            /**
             * @brief Get the Skin object
             * 
             * @return ne::Skin& 
             */
            ne::Skin& getSkin();

            ne::Skin skin;
    };
}

#endif /* !BACKGROUND_HPP */
