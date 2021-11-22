/*
** EPITECH PROJECT, 2021
** PlayerSystem
** File description:
** PlayerSystem
*/

#ifndef PLAYERSYSTEM_HPP_
#define PLAYERSYSTEM_HPP_

#include <NekoEngine/NekoEngine.hpp>
#include "Controller.hpp"

namespace rt {
    class PlayerSystem : public ne::System {
        public:
            void update(float dt, std::shared_ptr<rt::CustomClient> client);
            void setUpKey(sf::Keyboard::Key key);
            void setDownKey(sf::Keyboard::Key key);
            void setLeftKey(sf::Keyboard::Key key);
            void setRightKey(sf::Keyboard::Key key);
            void setShootKey(sf::Keyboard::Key key);
            void setPlayerSpeed(float speed);
            void setJoystickDeadzone(int deadzone);
            ne::Transform& getPlayerTrans();
            bool isShooting;
    };
}

#endif /* !PLAYERSYSTEM_HPP_ */
