/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves1
*/
#include "../../Ennemies/EnnemiesFactory.hpp"
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../../Ennemies/Ennemies.hpp"
#include "../AWaves.hpp"
#ifndef WAVES1_HPP_
#define WAVES1_HPP_

namespace ne {
    class Waves1 : public AWaves {
        public:
            /**
             * @brief Construct a new Waves 1 object
             * 
             */
            Waves1();

            /**
             * @brief Destroy the Waves 1 object
             * 
             */
            ~Waves1();

            /**
             * @brief Launch wave
             * 
             * @param uint32_t& ID 
             * @param std::shared_ptr<ne::Coordinator>& coordinator 
             */
            void LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator);
            ne::EnnemiesFactory factory;
        protected:
        private:
    };
}

#endif /* !WAVES1_HPP_ */
