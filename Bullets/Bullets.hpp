/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bullets
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BULLETS_HPP_
#define BULLETS_HPP_

namespace ne {
    class Bullets {
        public:
            Bullets();
            ~Bullets();

            ne::Transform getTransform();

            ne::Gravity getGravity();

            ne::RigidBody getRigidBody();

            ne::Skin getSkin();

            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Renderable renderable;
            ne::Skin skin;
        protected:
        private:
    };
}

#endif /* !BULLETS_HPP_ */
