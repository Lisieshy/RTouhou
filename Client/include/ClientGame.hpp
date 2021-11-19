/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientGame
*/

#ifndef CLIENTGAME_HPP_
#define CLIENTGAME_HPP_

#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../../Game/Ennemies/Ennemies.hpp"
#include "../../Game/Bullets/BulletsFactory.hpp"

namespace ne {
    class ClientGame {
        public:
            ClientGame();
            ~ClientGame();

            std::shared_ptr<ne::RenderSystem> RenderSystem;
            std::shared_ptr<rt::CustomClient> ClientSystem;

            ne::Scene ClientGameScene;
        protected:
        private:
    };
}

#endif /* !CLIENTGAME_HPP_ */
