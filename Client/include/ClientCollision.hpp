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

namespace ne {
    class ClientCollision : public ne::System {
        public:
            void update();

            void removeEnnemies(std::vector<ne::EntityID>& EnnemiesToBeDestroyed);

            void removeBullets(std::vector<ne::EntityID>& BulletsToBeDestroyed);
        
            void removeBonus(std::vector<ne::EntityID>& BonusToBeDestroyed);

            void removePlayer(std::vector<ne::EntityID>& PlayerToBeDestroyed);
    };
}

#endif /* !CLIENTCOLLISION_HPP_ */
