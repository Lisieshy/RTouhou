/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Player
*/

/**
 * @file        Player.hpp
 * @brief       Player class
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        18/11/2021
 */

#include <NekoEngine/NekoEngine.hpp>
#include <functional>
#include "../GlobalTexture/GlobalTexture.hpp"
#include <include/Controller.hpp>

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class Player {
        public:
        //     /**
        //      * @brief Construct a new Ennemies object
        //      * 
        //      */
        //     Player();

        //     /**
        //      * @brief Destroy the Ennemies object
        //      * 
        //      */
        //     ~Player();

        //     /**
        //      * @brief Get the Transform object
        //      * 
        //      * @return ne::Transform& 
        //      */
        //     ne::Transform& getTransform();

        //     /**
        //      * @brief Get the Gravity object
        //      * 
        //      * @return ne::Gravity& 
        //      */
        //     ne::Gravity& getGravity();

        //     /**
        //      * @brief Get the Rigid Body object
        //      * 
        //      * @return ne::RigidBody& 
        //      */
        //     ne::RigidBody& getRigidBody();

        //     /**
        //      * @brief Get the Color object
        //      * 
        //      * @return ne::Color& 
        //      */
        //     ne::Color& getColor();

        //     /**
        //      * @brief Get the Skin object
        //      * 
        //      * @return ne::Skin&
        //      */
        //     ne::Skin& getSkin();

        //     /**
        //      * @brief Get the Controller object
        //      * 
        //      * @return rt::Controller&
        //      */
        //     rt::Controller& getController();

        //     /**
        //      * @brief Get the Type object
        //      * 
        //      * @return ne::EntityType::Type& 
        //      */
        //     ne::EntityType::Type& getType();

        //     /**
        //      * @brief Get the Uid object
        //      * 
        //      * @return ne::Uid& 
        //      */
        //     ne::Uid& getUid();

        //     /**
        //      * @brief Set the Transform object
        //      * 
        //      * @param ne::Transform 
        //      */
        //     void setTransform(ne::Transform trans);

        //     /**
        //      * @brief Set the Gravity object
        //      * 
        //      * @param ne::Gravity 
        //      */
        //     void setGravity(ne::Gravity grav);

        //     /**
        //      * @brief Set the Color object
        //      * 
        //      * @param ne::Color 
        //      */
        //     void setColor(ne::Color col);

        //     /**
        //      * @brief Set the Skin object
        //      * 
        //      * @param ne::Skin 
        //      */
        //     void setSkin(ne::Skin sk);

        //     /**
        //      * @brief Set the Rigit Body object
        //      * 
        //      * @param ne::RigidBody 
        //      */
        //     void setRigitBody(ne::RigidBody rigid);

        //     /**
        //      * @brief Set the Controller object
        //      * 
        //      * @param rt::Controller
        //      */
        //     void setController(rt::Controller ctr);

        //     /**
        //      * @brief Set the Type of the object
        //      * 
        //      * @param ne::EntityType::Type
        //      */
        //     void setType(ne::EntityType::Type);

        //     /**
        //      * @brief Set the UID of the object
        //      * 
        //      * @param ne::Uid
        //      */
        //     void setUid(ne::Uid);
        // protected:
        public:
            ne::Transform transform;
            ne::Gravity gravity;
            ne::RigidBody rigidbody;
            ne::Color color;
            ne::Skin skin;
            rt::Controller controller;
            ne::EntityType::Type type;
            ne::Uid id;
    };
}

#endif /* !ENNEMIES_HPP_ */
