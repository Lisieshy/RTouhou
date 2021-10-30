/*
** EPITECH PROJECT, 2021
** ComponentManager
** File description:
** ComponentManager
*/

/**
 * @file        ComponentManager.hpp
 * @brief       Component Manmager class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <array>
#include <map>
#include <memory>
#include "NekoEngine/ECS/Types.hpp"
#include "NekoEngine/ECS/ComponentArray.hpp"

namespace ne {
    class ComponentManager {
        public:
            template<typename T>
            void registerComponent();

            template<typename T>
            ComponentType getComponentType();

            template<typename T>
            void addComponent(EntityID entity, T component);

            template<typename T>
            void removeComponent(EntityID entity);

            template<typename T>
            T& getComponent(EntityID entity);

            void entityDestroyed(EntityID entity);
        private:
            std::map<const char*, ComponentType> m_componentTypes{};
            std::map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};
            ComponentType m_nextComponentType{};

            template<typename T>
            std::shared_ptr<ComponentArray<T>> getComponentArray();
    };
}

#include "ComponentManager.tpp"

#endif /* !COMPONENTMANAGER_HPP_ */
