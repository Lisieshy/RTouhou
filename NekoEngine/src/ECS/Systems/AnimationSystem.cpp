/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** AnimationSystem
*/

#include "NekoEngine/ECS/Coordinator.hpp"
#include "NekoEngine/ECS/Systems/AnimationSystem.hpp"
#include "NekoEngine/ECS/Components/Components.hpp"
#include <iostream>

void ne::AnimationSystem::update(float dt)
{
    animationTime -= dt;
    if (animationTime <= 0.f) {
        animationTime = 0.5f;
        for (auto & entity : m_entities) {
            auto& spr = coordinator->getComponent<ne::Skin>(entity);

            sf::IntRect NewRect = spr.sprite.getTextureRect();
            NewRect.left += NewRect.width;
            if (NewRect.left >= spr.sprite.getTexture()->getSize().x - 30)
                NewRect.left = 0;
            spr.sprite.setTextureRect(NewRect);
        }
    }
}