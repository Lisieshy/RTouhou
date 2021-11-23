/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** FriendlyBullets
*/

#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef FRIENDLYBULLETS_HPP_
#define FRIENDLYBULLETS_HPP_

namespace ne {
    class FriendlyBullets : public Bullets {
        public:
            /**
             * @brief Construct a new Friendly Bullets object
             * 
             */
            FriendlyBullets();

            /**
             * @brief Destroy the Friendly Bullets object
             * 
             */
            ~FriendlyBullets();

        protected:
        private:
    };
}

#endif /* !FRIENDLYBULLETS_HPP_ */
