/*
** EPITECH PROJECT, 2021
** Types
** File description:
** Types
*/

/**
 * @file        Types.hpp
 * @brief       NekoEngine types definition
 * @details     It's as simple as it gets for an ECS implementation.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <cstdint>
#include <bitset>

namespace ne {
    using EntityID = std::uint32_t;
    const EntityID MAX_ENTITIES = 0x100000; // Going higher than this can cause a lot of problems during compilation. I'd advise you not to.
    using ComponentType = std::uint32_t;
    const ComponentType MAX_COMPONENTS = 0x100;
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif /* !TYPES_HPP_ */
