/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsPlT3
*/
#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>

#ifndef BULLETSPLT3_HPP_
#define BULLETSPLT3_HPP_

namespace ne {
    class BulletsPlT3 : public Bullets {
        public:
            /**
             * @brief Construct a new Bullets PlT3 object
             * 
             */
            BulletsPlT3();

            /**
             * @brief Destroy the Bullets PlT3 object
             * 
             */
            ~BulletsPlT3();

        protected:
        private:
    };
}

#endif /* !BULLETSPLT3_HPP_ */
