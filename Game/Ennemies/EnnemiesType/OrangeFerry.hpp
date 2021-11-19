/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** OrangeFerry
*/

/**
 * @file        OrangeFerry.hpp
 * @brief       Tier 4 ennemie
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef ORANGEFERRY_HPP_
#define ORANGEFERRY_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class OrangeFerry : public Ennemies {
        public:
            /**
             * @brief Construct a new Orange Ferry object
             * 
             */
            OrangeFerry();

            /**
             * @brief Destroy the Orange Ferry object
             * 
             */
            ~OrangeFerry();
        protected:
        private:
    };
}
#endif /* !ORANGEFERRY_HPP_ */
