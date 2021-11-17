/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameScene
*/

#include <unordered_map>
#include "GameEnnemiesLoop.hpp"

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

namespace ne {
    class GameScene {
        public:
            GameScene(std::vector<ne::EntityID> Entity);
            ~GameScene();

            void GameLoop(float dt);

            void InitScene();

            void setEntity(uint32_t ID);

            uint32_t getEntity();

            std::unordered_map<uint32_t, std::shared_ptr<ne::Ennemies>> EnnemiesAlive;

            std::shared_ptr<ne::RenderSystem> RenderSystem;
            std::shared_ptr<ne::PatternSystem> PatternSystem;
            std::shared_ptr<rt::CustomClient> ClientSystem;
            std::shared_ptr<ne::GameEnnemiesLoop> EnnemiesLoopSystem;

            ne::Scene Game;

            std::vector<ne::EntityID> entities;

            ne::EnnemiesFactory fact;
            ne::BulletsFactory bullets;

            uint32_t entityID = 0;
            size_t a = 99;
        protected:
        private:
    };
}

#endif /* !GAMESCENE_HPP_ */
