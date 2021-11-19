/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves1
*/
#include "../Ennemies/EnnemiesFactory.hpp"
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../Game/Ennemies/Ennemies.hpp"

#ifndef WAVES1_HPP_
#define WAVES1_HPP_

namespace ne {
    class Waves1 {
        public:
            Waves1(uint32_t ID, std::shared_ptr<ne::Coordinator> coordinator);
            ~Waves1();

            ne::EnnemiesFactory factory;
        protected:
        private:
    };
}

#endif /* !WAVES1_HPP_ */
