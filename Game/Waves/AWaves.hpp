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
            /**
             * @brief Construct a new AWaves object
             * 
             */
            AWaves();

            /**
             * @brief Destroy the AWaves object
             * 
             */
            ~AWaves();

            /**
             * @brief Check if the wave is finished
             * 
             * @param dt 
             * @return true 
             * @return false 
             */
            bool IsWaveFinished(float dt);

            /**
             * @brief Launch wave
             * 
             * @param uint32_t& ID 
             * @param std::shared_ptr<ne::Coordinator>& coordinator 
             */
            void LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator);

            /**
             * @brief reset wave
             * 
             */
            void resetWave();
            float WaveTime = 15.0f;
        protected:
        private:
    };
}

#endif /* !AWAVES_HPP_ */
