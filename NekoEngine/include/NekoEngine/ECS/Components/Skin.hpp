/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Skin
*/


/**
 * @file        Skin.hpp
 * @brief       Skin component
 * @details     ECS are fun, ECS are life.
 * @author      Tom Wederich (@TheGorb)
 * @date        13/11/2021
 */


#include <SFML/Graphics.hpp>
#ifndef SKIN_HPP_
#define SKIN_HPP_

namespace ne {
    class Skin {
        public:
            sf::Sprite sprite;
            sf::Texture texture;
            std::string name;
    };
}

#endif /* !SKIN_HPP_ */
