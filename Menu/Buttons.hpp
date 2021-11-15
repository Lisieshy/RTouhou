/*
** EPITECH PROJECT, 2021
** Buttons.hpp
** File description:
** Buttons.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BUTTONS_HPP
#define BUTTONS_HPP

namespace ne {
    class Buttons {
        public:
            Buttons(const std::string &name, const std::string &text, ne::Math::Vector2u pos);
            ~Buttons();

        protected:
        private:
    };
}

#endif /* !BUTTONS_HPP */
