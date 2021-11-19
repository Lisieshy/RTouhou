/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicWhiteBullets
*/

/**
 * @file        BasicWhiteBullets.hpp
 * @brief       Tier 1 bullets class
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BASICWHITEBULLETS_HPP_
#define BASICWHITEBULLETS_HPP_
/**
 * @namespace ne
 */
namespace ne {
    /**
     * @class BasicWhiteBullets from Bullets
     */
    class BasicWhiteBullets : public Bullets {
        public:
            /**
             * @brief Constructor
             */
            BasicWhiteBullets();

            /**
             * @brief Destructor
             */
            ~BasicWhiteBullets();
        protected:
        private:
    };
}

#endif /* !BASICWHITEBULLETS_HPP_ */