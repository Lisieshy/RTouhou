/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves4
*/

#include "../../Ennemies/EnnemiesFactory.hpp"
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../../Ennemies/Ennemies.hpp"
#include "../AWaves.hpp"
#include "Waves3.hpp"
#include "Waves2.hpp"
#include "Waves1.hpp"

#ifndef WAVES4_HPP_
#define WAVES4_HPP_

namespace ne {
    class Waves4 : public AWaves {
        public:
            /**
             * @brief Construct a new Waves 4 object
             * 
             */
            Waves4();

            /**
             * @brief Destroy the Waves 4 object
             * 
             */
            ~Waves4();

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

#endif /* !WAVES4_HPP_ */