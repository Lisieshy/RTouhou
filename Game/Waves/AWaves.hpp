/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** AWaves
*/

#ifndef AWAVES_HPP_
#define AWAVES_HPP_

#include "IWaves.hpp"

namespace ne {
    class AWaves : public ne::IWaves {
        public:
            AWaves();
            ~AWaves();
            bool IsWaveFinished(float dt);
            void LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator);

            float WaveTime = 15.0f;
        protected:
        private:
    };
}

#endif /* !AWAVES_HPP_ */
