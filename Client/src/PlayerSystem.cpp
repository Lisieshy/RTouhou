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


void rt::PlayerSystem::update(float dt)
{
    isShooting = false;
    for (auto& entity : m_entities) {
        auto& transform = coordinator->getComponent<ne::Transform>(entity);
        auto& rigidbody = coordinator->getComponent<ne::RigidBody>(entity);
        auto& controller = coordinator->getComponent<rt::Controller>(entity);

        switch (controller.type) {
            case rt::ControlType::KEYBOARD:
                if (sf::Keyboard::isKeyPressed(controller.up)) {
                    transform.position.y += -controller.speed * dt;
                }
                if (sf::Keyboard::isKeyPressed(controller.down)) {
                    transform.position.y += controller.speed * dt;
                }
                if (sf::Keyboard::isKeyPressed(controller.left)) {
                    transform.position.x += -controller.speed * dt;
                }
                if (sf::Keyboard::isKeyPressed(controller.right)) {
                    transform.position.x += controller.speed * dt;
                }
                if (sf::Keyboard::isKeyPressed(controller.shoot)) {
                    isShooting = true;
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
    }
}