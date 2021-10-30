/*
** EPITECH PROJECT, 2021
** ComponentArray
** File description:
** ComponentArray
*/

/**
 * @file        ComponentArray.hpp
 * @brief       Component Array template class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef COMPONENTARRAY_HPP_
#define COMPONENTARRAY_HPP_

#include <array>
#include <map>
#include <memory>
#include "NekoEngine/ECS/IComponentArray.hpp"

namespace ne {
    template<typename T>
    class ComponentArray : public IComponentArray {
        public:
            void insertData(EntityID entity, T component);
            void removeData(EntityID entity);
            T& getData(EntityID entity);
            void entityDestroyed(EntityID entity) override;
        private:
            std::unique_ptr<std::array<T, MAX_ENTITIES>> m_components = std::make_unique<std::array<T, MAX_ENTITIES>>();
            std::map<EntityID, size_t> m_entityToIndex;
            std::map<size_t, EntityID> m_IndexToEntity;
            size_t m_size;
    };
}

#include "ComponentArray.tpp"

#endif /* !COMPONENTARRAY_HPP_ */
