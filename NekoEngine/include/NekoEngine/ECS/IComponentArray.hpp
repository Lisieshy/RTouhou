/*
** EPITECH PROJECT, 2021
** IComponentArray
** File description:
** IComponentArray
*/

/**
 * @file        IComponentArray.hpp
 * @brief       Interface for the Component Array template class
 * @details     ECS are fun, ECS are life.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef ICOMPONENTARRAY_HPP_
#define ICOMPONENTARRAY_HPP_

#include "NekoEngine/ECS/Types.hpp"

namespace ne {
    class IComponentArray {
        public:
            virtual ~IComponentArray() = default;
            virtual void entityDestroyed(ne::EntityID entity) = 0;
    };
}

#endif /* !ICOMPONENTARRAY_HPP_ */
