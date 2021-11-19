/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Ennemies
*/

/**
 * @file        Ennemmies.hpp
 * @brief       Ennemies class
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include "HitPoint.hpp"
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include <../NekoEngine/include/NekoEngine/Math/Vector/Vector.hpp>
#include <../NekoEngine/include/NekoEngine/ECS/Components/Components.hpp>
#include <functional>
#include "../GlobalTexture/GlobalTexture.hpp"

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class Ennemies {
        public:
            /**
             * @brief Construct a new Ennemies object
             * 
             */
            Ennemies();

            /**
             * @brief Destroy the Ennemies object
             * 
             */
            ~Ennemies();

            /**
             * @brief Get the Transform object
             * 
             * @return ne::Transform& 
             */
            ne::Transform& getTransform();

            /**
             * @brief Get the Gravity object
             * 
             * @return ne::Gravity& 
             */
            ne::Gravity& getGravity();

            /**
             * @brief Get the Rigid Body object
             * 
             * @return ne::RigidBody& 
             */
            ne::RigidBody& getRigidBody();

            /**
             * @brief Get the Color object
             * 
             * @return ne::Color& 
             */
            ne::Color& getColor();

            /**
             * @brief Get the Skin object
             * 
             * @return ne::Skin&
             */
            ne::Skin& getSkin();

            /**
             * @brief Get the Alien object
             * 
             * @return ne::Alien&
             */
            ne::Alien& getAlien();

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
             * @brief Set the Alien object
             * 
             * @param ne::Alien 
             */
            void setAlien(ne::Alien ali);

            /**
             * @brief Set the Pattern object
             * 
             * @param std::function<ne::Math::Vector3f()>
             */
            void setPattern(std::function<ne::Math::Vector3f()>);

            /**
             * @brief Set the Type of the object
             * 
             * @param ne::EntityType::Type
             */
            void setType(ne::EntityType::Type);
        protected:
        private:
            ne::Patterns pat;
            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Color color;
            ne::Skin skin;
            ne::Alien alien;
            ne::EntityType::Type type;
    };
}

#endif /* !ENNEMIES_HPP_ */
