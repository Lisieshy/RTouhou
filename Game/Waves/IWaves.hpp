/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** IWaves
*/

#ifndef IWAVES_HPP_
#define IWAVES_HPP_

#include "NekoEngine/ECS/System.hpp"

namespace ne {
    class IWaves {
        public:
            virtual ~IWaves() = default;
            virtual bool IsWaveFinished(float dt) = 0;
            virtual void LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator) = 0;
        protected:
        private:
    };
}

#endif /* !IWAVES_HPP_ */
