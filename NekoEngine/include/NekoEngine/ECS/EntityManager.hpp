/*
** EPITECH PROJECT, 2021
** EntityManager
** File description:
** EntityManager
*/

/**
 * @file        EntityManager.hpp
 * @brief       Entities are fun
 * @details     It's as simple as it gets for an ECS implementation.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <queue>
#include <array>
#include <memory>
#include "NekoEngine/ECS/Types.hpp"

namespace ne {
    class EntityManager {
        public:
            EntityManager();

            EntityID createEntity();
            void destroyEntity(EntityID entity);
            void setSignature(EntityID entity, Signature signature);
            Signature getSignature(EntityID entity);

        private:
            std::queue<EntityID> m_availableEntities{};
            std::unique_ptr<std::array<Signature, MAX_ENTITIES>> m_signatures = std::make_unique<std::array<Signature, MAX_ENTITIES>>();
            uint32_t m_livingEntities{};
    };
}

#endif /* !ENTITYMANAGER_HPP_ */
