/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicPlane
*/
#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BASICPLANE_HPP_
#define BASICPLANE_HPP_

namespace ne {
    class BasicPlane : public Ennemies {
        public:
            BasicPlane();
            ~BasicPlane();

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

#endif /* !BASICPLANE_HPP_ */
