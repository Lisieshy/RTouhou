/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** DarkBlueFerry
*/
#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef DARKBLUEFERRY_HPP_
#define DARKBLUEFERRY_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class DarkBlueFerry : public Ennemies {
        public:
            /**
             * @brief Construct a new Dark Blue Ferry object
             * 
             */
            DarkBlueFerry();

            /**
             * @brief Destroy the Dark Blue Ferry object
             * 
             */
            ~DarkBlueFerry();
        protected:
        private:
    };
}

#endif /* !DARKBLUEFERRY_HPP_ */
