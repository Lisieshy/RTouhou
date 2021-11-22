/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** ClientCollision
*/

#include "../include/ClientCollision.hpp"

void ne::ClientCollision::update()
{
    std::vector<ne::EntityID> EnnemiesToBeDestroyed;
    std::vector<ne::EntityID> BulletsToBeDestroyed;

    for (auto entity : m_entities) {
        auto& EnnemiesType = coordinator->getComponent<ne::EntityType::Type>(entity);
        if (EnnemiesType <= ne::EntityType::Type::WhiteEnnemy) {
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
            for (auto ComparedEntity : m_entities) {
                auto& ComparedEnnemiesType = coordinator->getComponent<ne::EntityType::Type>(ComparedEntity);
                if (ComparedEnnemiesType == ne::EntityType::FriendlyBullets) {
                    auto& Comparedtransform = coordinator->getComponent<ne::Transform>(ComparedEntity);
                    if (Comparedtransform.position.x > transform.position.x && Comparedtransform.position.x < transform.position.x + 34 &&
                        Comparedtransform.position.y > transform.position.y && Comparedtransform.position.y < transform.position.y + 32) {
                        if (std::find(EnnemiesToBeDestroyed.begin(), EnnemiesToBeDestroyed.end(), entity) == EnnemiesToBeDestroyed.end())
                            EnnemiesToBeDestroyed.push_back(entity);
                        if (std::find(BulletsToBeDestroyed.begin(), BulletsToBeDestroyed.end(), ComparedEntity) == BulletsToBeDestroyed.end())
                            BulletsToBeDestroyed.push_back(ComparedEntity);
                    }
                }
            }
        }
    }
    removeEnnemies(EnnemiesToBeDestroyed);
    removeBullets(BulletsToBeDestroyed);
}

void ne::ClientCollision::removeEnnemies(std::vector<ne::EntityID>& EnnemiesToBeDestroyed)
{
    for (auto ID : EnnemiesToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(ID);
        coordinator->removeComponent<ne::RigidBody>(ID);
        coordinator->removeComponent<ne::Renderable>(ID);
        coordinator->removeComponent<ne::Color>(ID);
        coordinator->removeComponent<ne::Skin>(ID);
        coordinator->removeComponent<ne::Alien>(ID);
        coordinator->removeComponent<ne::EntityType::Type>(ID);
        coordinator->removeComponent<ne::Patterns>(ID);
        coordinator->removeComponent<ne::Uid>(ID);
        coordinator->removeComponent<ne::Animation>(ID);
        coordinator->destroyEntity(ID);
    }
}

void ne::ClientCollision::removeBullets(std::vector<ne::EntityID>& BulletsToBeDestroyed)
{
    for (auto ID : BulletsToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(ID);
        coordinator->removeComponent<ne::RigidBody>(ID);
        coordinator->removeComponent<ne::Renderable>(ID);
        coordinator->removeComponent<ne::Color>(ID);
        coordinator->removeComponent<ne::Skin>(ID);
        coordinator->removeComponent<ne::EntityType::Type>(ID);
        coordinator->removeComponent<ne::Patterns>(ID);
        coordinator->removeComponent<ne::Uid>(ID);
        coordinator->destroyEntity(ID);
    }
}