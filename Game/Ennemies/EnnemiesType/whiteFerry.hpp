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

namespace ne {
    class whiteFerry : public Ennemies {
        public:
            whiteFerry();
            ~whiteFerry();
        
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

#endif /* !WHITEFERRY_HPP_ */
