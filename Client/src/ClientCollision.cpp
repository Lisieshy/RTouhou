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
    std::vector<ne::EntityID> BonusToBeDestoyed;
    std::vector<ne::EntityID> PlayerToBeDestoyed;

    for (auto entity : m_entities) {
        auto& EnnemiesType = coordinator->getComponent<ne::EntityType::Type>(entity);
        if (EnnemiesType <= ne::EntityType::Type::WhiteEnnemy) {
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
            for (auto ComparedEntity : m_entities) {
                auto& ComparedEnnemiesType = coordinator->getComponent<ne::EntityType::Type>(ComparedEntity);
                if (ComparedEnnemiesType >= ne::EntityType::FriendlyPlT2 && ComparedEnnemiesType <= ne::EntityType::FriendlyBullets) {
                    auto& Comparedtransform = coordinator->getComponent<ne::Transform>(ComparedEntity);
                    if (Comparedtransform.position.x > transform.position.x && Comparedtransform.position.x < transform.position.x + 34 &&
                        Comparedtransform.position.y > transform.position.y && Comparedtransform.position.y < transform.position.y + 32) {
                        if (std::find(EnnemiesToBeDestroyed.begin(), EnnemiesToBeDestroyed.end(), ComparedEntity) == EnnemiesToBeDestroyed.end())
                            EnnemiesToBeDestroyed.push_back(entity);
                        if (std::find(BulletsToBeDestroyed.begin(), BulletsToBeDestroyed.end(), ComparedEntity) == BulletsToBeDestroyed.end())
                            BulletsToBeDestroyed.push_back(ComparedEntity);
                    }
                }
            }
        } else if (EnnemiesType == ne::EntityType::Type::Player) {
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
            for (auto ComparedEntity : m_entities) {
                auto& ComparedEnnemiesType = coordinator->getComponent<ne::EntityType::Type>(ComparedEntity);
                if (ComparedEnnemiesType == ne::EntityType::ScoreUp) {
                    auto& Comparedtransform = coordinator->getComponent<ne::Transform>(ComparedEntity);
                    if (Comparedtransform.position.x > transform.position.x && Comparedtransform.position.x < transform.position.x + 32 &&
                        Comparedtransform.position.y > transform.position.y && Comparedtransform.position.y < transform.position.y + 28) {
                        if (std::find(BonusToBeDestoyed.begin(), BonusToBeDestoyed.end(), ComparedEntity) == BonusToBeDestoyed.end())
                            BonusToBeDestoyed.push_back(ComparedEntity);
                    }
                }  if (ComparedEnnemiesType <= ne::EntityType::Type::Tier3Bullets) {
                    auto& Comparedtransform = coordinator->getComponent<ne::Transform>(ComparedEntity);
                    if (Comparedtransform.position.x > transform.position.x && Comparedtransform.position.x < transform.position.x + 32 &&
                        Comparedtransform.position.y > transform.position.y && Comparedtransform.position.y < transform.position.y + 28) {
                        if (ComparedEnnemiesType <= ne::EntityType::Type::WhiteEnnemy)
                            if (std::find(EnnemiesToBeDestroyed.begin(), EnnemiesToBeDestroyed.end(), ComparedEntity) == EnnemiesToBeDestroyed.end()) {
                                EnnemiesToBeDestroyed.push_back(ComparedEntity);
                            }
                        else if (ComparedEnnemiesType <= ne::EntityType::Type::Tier3Bullets)
                            if (std::find(BulletsToBeDestroyed.begin(), BulletsToBeDestroyed.end(), ComparedEntity) == BulletsToBeDestroyed.end()) {
                                BulletsToBeDestroyed.push_back(ComparedEntity);
                            }
                        if (std::find(PlayerToBeDestoyed.begin(), PlayerToBeDestoyed.end(), entity) == PlayerToBeDestoyed.end()) {
                            PlayerToBeDestoyed.push_back(entity);
                        }
                        break;
                    }
                }
            }
        } else {
            auto& transform = coordinator->getComponent<ne::Transform>(entity);
            if (transform.position.y > 600 || transform.position.x < -395 || transform.position.x > 1195 || transform.position.y < -400) {
                if (EnnemiesType <= ne::EntityType::Type::WhiteEnnemy)
                    if (std::find(EnnemiesToBeDestroyed.begin(), EnnemiesToBeDestroyed.end(), entity) == EnnemiesToBeDestroyed.end())
                        EnnemiesToBeDestroyed.push_back(EnnemiesType);
                else if (EnnemiesType <= ne::EntityType::Type::Bullets)
                    if (std::find(BulletsToBeDestroyed.begin(), BulletsToBeDestroyed.end(), entity) == BulletsToBeDestroyed.end())
                        BulletsToBeDestroyed.push_back(EnnemiesType);                
            }

        }
    }
    removeEnnemies(EnnemiesToBeDestroyed);
    removeBullets(BulletsToBeDestroyed);
    removeBonus(BonusToBeDestoyed);
    removePlayer(PlayerToBeDestoyed);
}

void ne::ClientCollision::removeEnnemies(std::vector<ne::EntityID>& EnnemiesToBeDestroyed)
{
    for (auto ID : EnnemiesToBeDestroyed) {
        std::cout << "In Ennemies" << std::endl;
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
        std::cout << "In Bullet" << std::endl;
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

void ne::ClientCollision::removeBonus(std::vector<ne::EntityID>& BonusToBeDestroyed)
{
    for (auto ID : BonusToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(ID);
        coordinator->removeComponent<ne::Renderable>(ID);
        coordinator->removeComponent<ne::Skin>(ID);
        coordinator->removeComponent<ne::EntityType::Type>(ID);
        coordinator->removeComponent<ne::Patterns>(ID);
        coordinator->removeComponent<ne::RigidBody>(ID);
        coordinator->removeComponent<ne::Color>(ID);
        coordinator->removeComponent<ne::Uid>(ID);
        coordinator->destroyEntity(ID);
    }
}

void ne::ClientCollision::removePlayer(std::vector<ne::EntityID>& PlayerToBeDestroyed)
{
    for (auto ID : PlayerToBeDestroyed) {
        coordinator->removeComponent<ne::Transform>(ID);
        coordinator->removeComponent<ne::Renderable>(ID);
        coordinator->removeComponent<ne::RigidBody>(ID);
        coordinator->removeComponent<ne::Color>(ID);
        coordinator->removeComponent<ne::Skin>(ID);
        coordinator->removeComponent<ne::EntityType::Type>(ID);
        coordinator->removeComponent<ne::Animation>(ID);
        coordinator->removeComponent<ne::Uid>(ID);
        coordinator->destroyEntity(ID);
    }
}
