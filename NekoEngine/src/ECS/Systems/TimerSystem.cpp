/*
** EPITECH PROJECT, 2021
** TimerSystem
** File description:
** TimerSystem
*/

#include "NekoEngine/ECS/Systems/Systems.hpp"
#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Components/Timer.hpp"
#include "NekoEngine/ECS/Components/Transform.hpp"
#include <cstring>

namespace ne {
    void TimerSystem::update()
    {
        for (auto& entity : m_entities) {
            auto& timer = coordinator->getComponent<ne::Timer>(entity);
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
        }
    }
}