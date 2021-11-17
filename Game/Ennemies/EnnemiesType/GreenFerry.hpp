/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GreenFerry
*/
#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef GREENFERRY_HPP_
#define GREENFERRY_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class GreenFerry : public Ennemies {
        public:
            /**
             * @brief Construct a new Green Ferry object
             * 
             */
            GreenFerry();

            /**
             * @brief Destroy the Green Ferry object
             * 
             */
            ~GreenFerry();
        protected:
        private:
    };
}
#endif /* !GREENFERRY_HPP_ */
