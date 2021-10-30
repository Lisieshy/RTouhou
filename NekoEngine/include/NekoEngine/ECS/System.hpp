/*
** EPITECH PROJECT, 2021
** System
** File description:
** System
*/

/**
 * @file        System.hpp
 * @brief       ECS System
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef MYSYSTEM_HPP_
#define MYSYSTEM_HPP_

#include <set>
#include <memory>
#include "NekoEngine/ECS/Types.hpp"

namespace ne {
    class Coordinator;

    class System {
        public:
            std::set<ne::EntityID> m_entities;
            std::shared_ptr<ne::Coordinator> coordinator;
    };
}

#endif /* !MYSYSTEM_HPP_ */
