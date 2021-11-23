/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsTier2
*/

#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BULLETSTIER2_HPP_
#define BULLETSTIER2_HPP_

namespace ne {
    class BulletsTier2 : public Bullets {
        public:
            /**
             * @brief Construct a new Bullets Tier2 object
             * 
             */
            BulletsTier2();

            /**
             * @brief Destroy the Bullets Tier2 object
             * 
             */
            ~BulletsTier2();

        protected:
        private:
    };
}
#endif /* !BULLETSTIER2_HPP_ */
