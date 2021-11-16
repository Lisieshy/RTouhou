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

namespace ne {
    class DarkBlueFerry : public Ennemies {
        public:
            DarkBlueFerry();
            ~DarkBlueFerry();

            virtual ne::Transform getTransform();
            virtual ne::Gravity getGravity();
            virtual ne::RigidBody getRigidBody();
            virtual ne::Color getColor();
            virtual ne::Skin getSkin();
            virtual ne::Alien getAlien();
        protected:
        private:
    };
}

#endif /* !DARKBLUEFERRY_HPP_ */
