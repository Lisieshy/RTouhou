/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameScene
*/

/**
 * @file        GameScene.hpp
 * @brief       Scene that manage the game
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include <unordered_map>
#include <NekoEngine/NekoEngine.hpp>
#include <NyaNet/NyaNet.hpp>
#include "GameEnnemiesLoop.hpp"
#include "../../Game/Ennemies/EnnemiesFactory.hpp"
#include "../../Game/Bullets/BulletsFactory.hpp"
#include "../../Server/src/CustomServer.cpp"
#include <include/PlayerSystem.hpp>

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

namespace ne {
    class GameScene {
        public:
            /**
             * @brief Construct a new Game Scene object
             * 
             * @param Entity 
             */
            GameScene(std::vector<ne::EntityID> &);

            /**
             * @brief Destroy the Game Scene object
             * 
             */
            ~GameScene();

            void GameLoop(float dt);

            void InitScene();

            void setEntity(uint32_t ID);

            std::unordered_map<uint32_t, std::shared_ptr<ne::Ennemies>> EnnemiesAlive;

            std::shared_ptr<ne::PatternSystem> PatternSystem;
            std::shared_ptr<ne::GameEnnemiesLoop> EnnemiesLoopSystem;
            std::shared_ptr<CustomServer> NetworkSystem;
            std::shared_ptr<rt::PlayerSystem> PlayerSystem;

            ne::Scene Game;

            std::vector<ne::EntityID> entities;

            ne::EnnemiesFactory fact;
            ne::BulletsFactory bullets;

            uint32_t entityID = 0;
        protected:
        private:
    };
}

#endif /* !GAMESCENE_HPP_ */
