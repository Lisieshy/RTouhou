/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** WavesClientSystem
*/

#ifndef WAVESCLIENTSYSTEM_HPP_
#define WAVESCLIENTSYSTEM_HPP_

#include <NekoEngine/NekoEngine.hpp>
#include "../../Game/GlobalLibrary/GlobalSound.hpp"

namespace ne {
    class WavesClientSystem : public ne::System {
        public:
            /**
             * @brief Init text for the wave
             * 
             */
            void init();

            /**
             * @brief Update text
             * 
             * @param float dt 
             */
            void update(float dt);

            float Time = 15.0f;
            int wave = 1;

            ne::Textinfo txtinfo;
    };
}
#endif /* !WAVESCLIENTSYSTEM_HPP_ */
