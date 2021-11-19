/*
** EPITECH PROJECT, 2021
** Controller
** File description:
** Controller
*/

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <SFML/Graphics.hpp>

namespace rt {
    enum class ControlType {
        NONE = -1,
        KEYBOARD,
        GAMEPAD,
    };

    class Controller {
        public:
            rt::ControlType type = rt::ControlType::NONE;

            sf::Keyboard::Key up = sf::Keyboard::Key::Unknown;
            sf::Keyboard::Key down = sf::Keyboard::Key::Unknown;
            sf::Keyboard::Key left = sf::Keyboard::Key::Unknown;
            sf::Keyboard::Key right = sf::Keyboard::Key::Unknown;
            sf::Keyboard::Key shoot = sf::Keyboard::Key::Unknown;

            float speed;
            int deadzone;
    };
}

#endif /* !CONTROLLER_HPP_ */
