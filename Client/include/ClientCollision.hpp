/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientCollision
*/

#ifndef CLIENTCOLLISION_HPP_
#define CLIENTCOLLISION_HPP_

#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Components.hpp"
#include "NekoEngine/ECS/Coordinator.hpp"
#include <iostream>

/**
 * @namespace ne
 * 
 */
namespace ne {
    class ClientCollision : public ne::System {
        public:
            /**
             * @brief Update all collision
             * 
             */
            void update();

            /**
             * @brief Destroy ennemies that collide with a friendly bullet or a player
             * 
             * @param std::vector<ne::EntityID>& 
             */
            void removeEnnemies(std::vector<ne::EntityID>& EnnemiesToBeDestroyed);

            /**
             * @brief Destroy bullets when the touch someone on the other side
             * 
             * @param std::vector<ne::EntityID>& 
             */
            void removeBullets(std::vector<ne::EntityID>& BulletsToBeDestroyed);
        
            /**
             * @brief Destroy bonus after being colected
             * 
             * @param std::vector<ne::EntityID>& 
             */
            void removeBonus(std::vector<ne::EntityID>& BonusToBeDestroyed);

            /**
             * @brief Destroy Player after getting shot
             * 
             * @param std::vector<ne::EntityID>& 
             */
            void removePlayer(std::vector<ne::EntityID>& PlayerToBeDestroyed);
    };
}

#endif /* !CLIENTCOLLISION_HPP_ */
