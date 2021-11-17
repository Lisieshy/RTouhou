/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** whiteFerry
*/
#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef WHITEFERRY_HPP_
#define WHITEFERRY_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class whiteFerry : public Ennemies {
        public:
            /**
             * @brief Construct a new white Ferry object
             * 
             */
            whiteFerry();

            /**
             * @brief Destroy the white Ferry object
             * 
             */
            ~whiteFerry();
        protected:
        private:
    };
}

#endif /* !WHITEFERRY_HPP_ */
