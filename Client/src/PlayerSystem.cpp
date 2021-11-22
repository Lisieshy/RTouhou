/*
** EPITECH PROJECT, 2021
** PlayerSystem
** File description:
** PlayerSystem
*/

#include <include/PlayerSystem.hpp>
#include <NekoEngine/NekoEngine.hpp>

void rt::PlayerSystem::setUpKey(sf::Keyboard::Key key)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.up = key;
    }
}

void rt::PlayerSystem::setDownKey(sf::Keyboard::Key key)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.down = key;
    }
}

void rt::PlayerSystem::setLeftKey(sf::Keyboard::Key key)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.left = key;
    }
}

void rt::PlayerSystem::setRightKey(sf::Keyboard::Key key)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.right = key;
    }
}

void rt::PlayerSystem::setShootKey(sf::Keyboard::Key key)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.shoot = key;
    }
}

void rt::PlayerSystem::setPlayerSpeed(float speed)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.speed = speed;
    }
}

void rt::PlayerSystem::setJoystickDeadzone(int deadzone)
{
    for (auto& entity : m_entities) {
        auto& control = coordinator->getComponent<rt::Controller>(entity);
        control.deadzone = deadzone;
    }
}

ne::Transform& rt::PlayerSystem::getPlayerTrans()
{
    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        return (transform);
    }
}


void rt::PlayerSystem::update(float dt, std::shared_ptr<rt::CustomClient> client)
{
    isShooting = false;
    nn::message<rt::CustomMsgTypes> _msg;
    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto& controller = coordinator->getComponent<rt::Controller>(entity);
        auto& id = coordinator->getComponent<ne::Uid>(entity);

        switch (controller.type) {
            case rt::ControlType::KEYBOARD:
                if (sf::Keyboard::isKeyPressed(controller.up)) {
                    transform.position.y += -controller.speed * dt;
                    _msg.header.id = rt::CustomMsgTypes::PlayerUp;
                }
                if (sf::Keyboard::isKeyPressed(controller.down)) {
                    transform.position.y += controller.speed * dt;
                    _msg.header.id = rt::CustomMsgTypes::PlayerDown;
                }
                if (sf::Keyboard::isKeyPressed(controller.left)) {
                    transform.position.x += -controller.speed * dt;
                    _msg.header.id = rt::CustomMsgTypes::PlayerLeft;
                }
                if (sf::Keyboard::isKeyPressed(controller.right)) {
                    transform.position.x += controller.speed * dt;
                    _msg.header.id = rt::CustomMsgTypes::PlayerRight;
                }
                if (sf::Keyboard::isKeyPressed(controller.shoot)) {
                    _msg.header.id = rt::CustomMsgTypes::PlayerIsShooting;
                }
            break;
            case rt::ControlType::GAMEPAD:
                if (sf::Joystick::isConnected(0)) {
                    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -controller.deadzone) {
                        transform.position.y += -controller.speed * dt;
                    }
                    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > controller.deadzone) {
                        transform.position.y += controller.speed * dt;
                    }
                    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -controller.deadzone) {
                        transform.position.x += -controller.speed * dt;
                    }
                    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > controller.deadzone) {
                        transform.position.x += controller.speed * dt;
                    }
                }
            break;
        }
        _msg << id << transform;
        client->Send(_msg); 
    }
}