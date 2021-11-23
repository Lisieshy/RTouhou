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

            std::vector<sf::Sprite> _par;
        protected:
        private:

    };
}

#endif /* !PARALLAX_HPP_ */
