/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

namespace ne {
    class GameScene {
        public:
            GameScene(std::vector<ne::EntityID> Entity);
            ~GameScene();

            void GameLoop();

            void InitScene();

            std::shared_ptr<ne::RenderSystem> RenderSystem;
            std::shared_ptr<ne::PhysicsSystem> PhysicsSystem;
            std::shared_ptr<rt::CustomClient> ClientSystem;

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
