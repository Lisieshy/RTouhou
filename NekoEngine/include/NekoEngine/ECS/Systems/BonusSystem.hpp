/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BonusSystem
*/

#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Components.hpp"
#include "../../../../../Game/Bonus/BonusFactory.hpp"
#include "NekoEngine/ECS/Coordinator.hpp"
#include <iostream>

#ifndef BONUSSYSTEM_HPP_
#define BONUSSYSTEM_HPP_

namespace ne {
    class BonusSystem : public ne::System {
        public:
            void update(float dt, uint32_t &ID);

            float Time = 1.0f;
        protected:
            ne::BonusFactory bonusFact;
        private:
    };
}

#endif /* !BONUSSYSTEM_HPP_ */
