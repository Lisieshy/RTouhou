/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsPlT2
*/
#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BULLETSPLT2_HPP_
#define BULLETSPLT2_HPP_

namespace ne {
    class BulletsPlT2 : public Bullets {
        public:
            /**
             * @brief Construct a new Bullets PlT2object
             * 
             */
            BulletsPlT2();

            /**
             * @brief Destroy the Bullets PlT2object
             * 
             */
            ~BulletsPlT2();

        protected:
        private:
    };
}

#endif /* !BULLETSPLT2_HPP_ */
