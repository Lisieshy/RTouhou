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
#include "../include/WavesClientSystem.hpp"
#include "PlayerSystem.hpp"
#include "NekoEngine/NekoEngine.hpp"
#include <SFML/Audio.hpp>
#include "ClientCollision.hpp"
#include "../include/Parallax.hpp"

/**
 * @namespace ne
 * 
 */
namespace ne {
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

            /**
             * @brief System to render graphical object
             * 
             */
            std::shared_ptr<ne::RenderSystem> RenderSystem;

            /**
             * @brief System to link client and server
             * 
             */
            std::shared_ptr<rt::CustomClient> ClientSystem;

            /**
             * @brief Player system for his movement
             * 
             */
            std::shared_ptr<rt::PlayerSystem> PlayerSystem;
            
            /**
             * @brief Animate sprite
             * 
             */
            std::shared_ptr<ne::AnimationSystem> AnimSystem;

            /**
             * @brief Check collision
             * 
             */
            std::shared_ptr<ne::ClientCollision> CollisionSystem;

            /**
             * @brief Wave system to display text for the wave
             * 
             */
            std::shared_ptr<ne::WavesClientSystem> WavesSystemClient;

            /**
             * @brief Render all text set
             * 
             */
            std::shared_ptr<ne::TextSystem> TextSystemClient;


            /**
             * @brief Render and create the paralax only on client side
             * 
             */
            std::shared_ptr<ne::Parallax> ParalaxSystemClient;
            
            /**
             * @brief Scene that manage everything
             * 
             */
            ne::Scene ClientGameScene;

            /**
             * @brief Create music
             * 
             */
            void InitMusic();
            sf::Music music;
        protected:
        private:
    };
}

#endif /* !CLIENTGAME_HPP_ */
