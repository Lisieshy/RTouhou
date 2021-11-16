/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Ennemies
*/
#include "HitPoint.hpp"
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

namespace ne {
    class Ennemies {
        public:
            Ennemies();
            ~Ennemies();

            virtual ne::Transform getTransform() = 0;

            virtual ne::Gravity getGravity() = 0;

            virtual ne::RigidBody getRigidBody() = 0;

            virtual ne::Color getColor() = 0;

            virtual ne::Skin getSkin() = 0;

            virtual ne::Alien getAlien() = 0;

            void setSkin();
        protected:
        private:
    };
}

#endif /* !ENNEMIES_HPP_ */
