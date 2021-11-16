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

namespace ne {
    class GreenFerry : public Ennemies {
        public:
            GreenFerry();
            ~GreenFerry();

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
#endif /* !GREENFERRY_HPP_ */
