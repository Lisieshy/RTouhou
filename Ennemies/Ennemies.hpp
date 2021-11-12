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

            ne::HitPoint getHitPoint();

            ne::Transform getTransform();

            ne::Gravity getGravity();

            ne::RigidBody getRigidBody();

            ne::Color getColor();
            ne::HitPoint hp;
            ne::Transform trans;
            ne::Gravity grav;
            ne::RigidBody rigid;
            ne::Renderable render;
            ne::Color temp;
        protected:
        private:
    };
}

#endif /* !ENNEMIES_HPP_ */
