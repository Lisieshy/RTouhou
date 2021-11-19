/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Wave
*/

#ifndef WAVE_HPP_
#define WAVE_HPP_

#include "WavesType/WaveInclude.hpp"

namespace ne {
    class Wave {
        public:
            Wave();
            ~Wave();
            void WaveLoop(float& dt, uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator);

            float time;
        protected:
        private:
    };
}

#endif /* !WAVE_HPP_ */
