/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves5
*/

#include "../../Ennemies/EnnemiesFactory.hpp"
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Components/Alien.hpp"
#include "../../Ennemies/Ennemies.hpp"
#include "../AWaves.hpp"
#include "Waves4.hpp"
#include "Waves3.hpp"
#include "Waves2.hpp"
#include "Waves1.hpp"

#ifndef WAVES5_HPP_
#define WAVES5_HPP_

namespace ne {
    class Waves5 : public AWaves {
        public:
            Waves5();
            ~Waves5();

            void LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator);
            ne::EnnemiesFactory factory;
        protected:
        private:
    };
}

#endif /* !WAVES5_HPP_ */