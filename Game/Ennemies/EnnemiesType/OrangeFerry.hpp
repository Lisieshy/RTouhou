/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** OrangeFerry
*/
#include "../Ennemies.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef ORANGEFERRY_HPP_
#define ORANGEFERRY_HPP_

namespace ne {
    class OrangeFerry : public Ennemies {
        public:
            OrangeFerry();
            ~OrangeFerry();

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
#endif /* !ORANGEFERRY_HPP_ */
