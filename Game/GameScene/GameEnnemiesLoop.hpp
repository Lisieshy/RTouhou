/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameEnnemiesLoop
*/

/**
 * @file        GameEnnemiesLoop.hpp
 * @brief       System for ennemies shoot
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#ifndef GAMEENNEMIESLOOP_HPP_
#define GAMEENNEMIESLOOP_HPP_

#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../Game/Ennemies/Ennemies.hpp"
#include "../Game/Bullets/BulletsFactory.hpp"

namespace ne {
    class GameEnnemiesLoop : public ne::System {
        public:
            /**
             * @brief 
             * 
             * @param float dt (time)
             * @param float ID (Ennemies ID) 
             * @return uint32_t 
             */
            void update(float& dt, uint32_t& ID);

            void createBullet(ne::Transform& EnnemiesPos, uint32_t& ID, ne::EntityType::Type& EnnemiesType);
    };  
}

#endif /* !GAMEENNEMIESLOOP_HPP_ */
