/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bullets
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BULLETS_HPP_
#define BULLETS_HPP_

/**
 * @namespace ne
 */
namespace ne {
    /**
     * @class Bullets
     */
    class Bullets {
        public:
            /**
             * @brief Constructor
             */
            Bullets();

            /**
             * @brief Destructor
             */
            ~Bullets();

            /**
             * @brief get Transform component
             * @return a ne::Transform
             */
            ne::Transform getTransform();

            /**
             * @brief get Gravity component
             * @return a ne::Gravity
             */
            ne::Gravity getGravity();

            /**
             * @brief get RigidBody component
             * @return a ne::RigidBody
             */
            ne::RigidBody getRigidBody();

            /**
             * @brief get Skin component
             * @return a ne::Skin
             */
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
