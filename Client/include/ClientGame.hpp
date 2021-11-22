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
#include "PlayerSystem.hpp"
#include "NekoEngine/NekoEngine.hpp"
#include <SFML/Audio.hpp>
#include "ClientCollision.hpp"
#include "../../Menu/Parallax.hpp"

/**
 * @namespace ne
 */

namespace ne {
    /**
     * @class ClientGame
     */
    class ClientGame {
        public:
            /**
             * @brief Construct a new Client Game object
             * 
             */
            ClientGame();
            /**
             * @brief Destroy the Client Game object
             * 
             */
            ~ClientGame();

            std::shared_ptr<ne::RenderSystem> RenderSystem;
            std::shared_ptr<rt::CustomClient> ClientSystem;
            std::shared_ptr<rt::PlayerSystem> PlayerSystem;
            std::shared_ptr<ne::AnimationSystem> AnimSystem;
            std::shared_ptr<ne::ClientCollision> CollisionSystem;
            std::shared_ptr<ne::ParallaxSystem> Parallax;
            ne::Scene ClientGameScene;
            
            /**
             * @brief 
             * 
             * @param dt float dt corresponding to the delta time 
             */
            void Update(float dt);

            /**
             * @brief Init the Music
             * 
             */
            void InitMusic();
            sf::Music music;
        protected:
        private:
    };
}

#endif /* !CLIENTGAME_HPP_ */
