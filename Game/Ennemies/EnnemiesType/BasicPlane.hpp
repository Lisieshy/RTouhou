/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicPlane
*/

/**
 * @file        BasicPlane.hpp
 * @brief       Tier 1 ennemie
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BASICPLANE_HPP_
#define BASICPLANE_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class BasicPlane : public Ennemies {
        public:
            /**
             * @brief Construct a new Basic Plane object
             * 
             */
            BasicPlane();

            /**
             * @brief Destroy the Basic Plane object
             * 
             */
            ~BasicPlane();
        protected:
        private:
    };
}

#endif /* !BASICPLANE_HPP_ */
