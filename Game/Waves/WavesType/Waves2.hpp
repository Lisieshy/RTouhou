/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves2
*/

#include "../../Ennemies/EnnemiesFactory.hpp"
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../../Ennemies/Ennemies.hpp"
#include "../AWaves.hpp"

#ifndef WAVES2_HPP_
#define WAVES2_HPP_

namespace ne {
    class Waves2 : public AWaves {
        public:
            /**
             * @brief Construct a new Waves 2 object
             * 
             */
            Waves2();

            /**
             * @brief Destroy the Waves 2 object
             * 
             */
            ~Waves2();

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

#endif /* !WAVES2_HPP_ */
