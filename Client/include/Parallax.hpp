/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include <NekoEngine/NekoEngine.hpp>
#include "../../Game/GlobalLibrary/GlobalTexture.hpp"

namespace ne {
    class Parallax : public ne::System {
        public:
            /**
             * @brief Construct a new Parallax object
             * 
             */
            Parallax();

            /**
             * @brief Destroy the Parallax object
             * 
             */
            ~Parallax();

            /**
             * @brief Update paralax
             * 
             * @param float dt 
             */
            void update(float dt);

            std::vector<sf::Sprite>_par;
            std::vector<sf::Sprite>_par2;
            std::vector<sf::Sprite>_par3;
            std::vector<sf::Sprite>_par4;
            std::vector<sf::Sprite>_par5;
            std::vector<sf::Sprite>_par6;
        protected:
        private:

    };
}

#endif /* !PARALLAX_HPP_ */
