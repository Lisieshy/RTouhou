/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bullets
*/

/**
 * @file        Bullets.hpp
 * @brief       Bullets class
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */


#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include "../GlobalTexture/GlobalTexture.hpp"
#include <../NekoEngine/include/NekoEngine/ECS/Components/Components.hpp>
#include <../NekoEngine/include/NekoEngine/Math/Vector/Vector.hpp>

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
             * @brief Get the Pattern object
             * 
             * @return ne::Patterns& 
             */
            ne::Patterns& getPattern();

            /**
             * @brief Get the Type object
             * 
             * @return ne::EntityType::Type&
             */
            ne::EntityType::Type& getType();

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

            /**
             * @brief Set the Pattern object
             * 
             * @param std::function<ne::Math::Vector3f()>
             */
            void setPattern(std::function<ne::Math::Vector3f()>);

            /**
             * @brief Set the Type object
             * 
             * @param ne::EntityType::Type 
             */
            void setType(ne::EntityType::Type newType);
        protected:
        private:
            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Color color;
            ne::Skin skin;
            ne::Patterns pat;
            ne::EntityType::Type Type;
    };
}

#endif /* !BULLETS_HPP_ */
