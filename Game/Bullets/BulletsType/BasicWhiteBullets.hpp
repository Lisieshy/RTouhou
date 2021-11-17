/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BasicWhiteBullets
*/
#include "../Bullets.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <sstream>
#ifndef BASICWHITEBULLETS_HPP_
#define BASICWHITEBULLETS_HPP_

namespace ne {
    class BasicWhiteBullets : public Bullets {
        public:
            BasicWhiteBullets();
            ~BasicWhiteBullets();
        protected:
        private:
    };
}

#endif /* !BASICWHITEBULLETS_HPP_ */