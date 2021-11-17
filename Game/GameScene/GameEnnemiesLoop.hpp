/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameEnnemiesLoop
*/

#ifndef GAMEENNEMIESLOOP_HPP_
#define GAMEENNEMIESLOOP_HPP_

#include "NekoEngine/ECS/System.hpp"

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
            uint32_t update(float dt, uint32_t ID);
    };  
}

#endif /* !GAMEENNEMIESLOOP_HPP_ */
