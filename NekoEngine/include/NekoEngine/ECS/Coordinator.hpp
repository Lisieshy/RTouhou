/*
** EPITECH PROJECT, 2021
** Coordinator
** File description:
** Coordinator
*/

/**
 * @file        Coordinator.hpp
 * @brief       Coordinator class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef COORDINATOR_HPP_
#define COORDINATOR_HPP_

#include "NekoEngine/ECS/ComponentManager.hpp"
#include "NekoEngine/ECS/EntityManager.hpp"
#include "NekoEngine/ECS/SystemManager.hpp"

namespace ne {
    class Coordinator {
        public:
            void init();
            ne::EntityID createEntity();
            void destroyEntity(ne::EntityID entity);

            template<typename T, typename ...Ts>
            void registerComponent();

            template<typename T>
            void addComponent(ne::EntityID entity, T component);

            template<typename T>
            void removeComponent(ne::EntityID entity);

            template<typename T>
            T& getComponent(ne::EntityID entity);

            template<typename T>
            ne::ComponentType getComponentType();

            template<typename T>
            std::shared_ptr<T> registerSystem(std::shared_ptr<ne::Coordinator> coordinator);

            template<typename T>
            void setSystemSignature(ne::Signature signature);

        protected:
            std::unique_ptr<ne::ComponentManager> m_componentManager;
            std::unique_ptr<ne::EntityManager> m_entityManager;
            std::unique_ptr<ne::SystemManager> m_systemManager;
    };
}

#include "Coordinator.tpp"

#endif /* !COORDINATOR_HPP_ */
