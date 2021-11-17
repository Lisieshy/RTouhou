/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bullets
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include "../GlobalTexture/GlobalTexture.hpp"

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

            /**
             * @brief Get the Color object@
             * @return ne::Color 
             */
            ne::Color getColor();

            /**
             * @brief Set the Transform object
             * 
             * @param ne::Transform 
             */
            void setTransform(ne::Transform trans);

            /**
             * @brief Set the Gravity object
             * 
             * @param ne::Gravity 
             */
            void setGravity(ne::Gravity grav);

            /**
             * @brief Set the Color object
             * 
             * @param ne::Color 
             */
            void setColor(ne::Color col);

            /**
             * @brief Set the Skin object
             * 
             * @param ne::Skin 
             */
            void setSkin(ne::Skin sk);

            /**
             * @brief Set the Rigit Body object
             * 
             * @param ne::RigidBody 
             */
            void setRigitBody(ne::RigidBody rigid);
        protected:
        private:
            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Color color;
            ne::Skin skin;
    };
}

#endif /* !BULLETS_HPP_ */
