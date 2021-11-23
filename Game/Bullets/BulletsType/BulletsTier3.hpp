/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsTier3
*/
#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BULLETSTIER3_HPP_
#define BULLETSTIER3_HPP_

namespace ne {
    class BulletsTier3 : public Bullets{
        public:
            /**
             * @brief Construct a new Bullets Tier 3 object
             * 
             */
            BulletsTier3();

            /**
             * @brief Destroy the Bullets Tier 3 object
             * 
             */
            ~BulletsTier3();

        protected:
        private:
    };
}

#endif /* !BULLETSTIER3_HPP_ */
