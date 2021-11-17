/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Ennemies
*/
#include "HitPoint.hpp"
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include "../GlobalTexture/GlobalTexture.hpp"

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

namespace ne {
    class Ennemies {
        public:
            Ennemies();
            ~Ennemies();

            ne::Transform getTransform();
            ne::Gravity getGravity();
            ne::RigidBody getRigidBody();
            ne::Color getColor();
            ne::Skin getSkin();
            ne::Alien getAlien();

            void setTransform(ne::Transform trans);
            void setGravity(ne::Gravity grav);
            void setColor(ne::Color col);
            void setSkin(ne::Skin sk);
            void setRigitBody(ne::RigidBody rigid);
            void setAlien(ne::Alien ali);
        protected:
        private:
            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Color color;
            ne::Skin skin;
            ne::Alien alien;
    };
}

#endif /* !ENNEMIES_HPP_ */
