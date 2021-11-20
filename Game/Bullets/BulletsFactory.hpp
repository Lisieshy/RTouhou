/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsFactory
*/

/**
 * @file        BulletsFactory.hpp
 * @brief       Factory to create all bullets
 * @author      Tom Wederich (@TheGorb)
 * @date        18/11/2021
 */

#include "Bullets.hpp"
#include "BulletsType/BulletsTypeInclude.hpp"
#ifndef BULLETSFACTORY_HPP_
#define BULLETSFACTORY_HPP_

/**
 * @namespace ne
 */
namespace ne {
    /**
     * @class BulletsFactory
     * 
     */
    class BulletsFactory {
        public:
            /**
             * @brief Construct a new Bullets Factory object
             */
            BulletsFactory();

            /**
             * @brief Destroy the Bullets Factory object
             */
            ~BulletsFactory();

            /**
             * @brief Create a Bullets object
             * 
             * @param std::string 
             * @return std::unique_ptr<ne::Bullets> 
             */
            std::unique_ptr<ne::Bullets> createBullets(const std::string &name);
        protected:
        private:
            /**
             * @brief Function pointer to create Bullets
             * 
             */

            /**
             * @brief Create the basic ennemie of the game
             * @return  std::unique_ptr<ne::Bullets>
             */
            std::map<std::string, std::unique_ptr<ne::Bullets>(ne::BulletsFactory::*)(const std::string &name) const> _create;
            std::unique_ptr<ne::Bullets> createBasicWhiteBullets(const std::string &name) const noexcept;
            std::unique_ptr<ne::Bullets> createTier3Bullets(const std::string &name) const noexcept;
            std::unique_ptr<ne::Bullets> createTier2Bullets(const std::string &name) const noexcept;
            std::unique_ptr<ne::Bullets> createFriendlyBullets(const std::string &name) const noexcept;
    };
}
using BulletsFact = std::unique_ptr<ne::Bullets>(ne::BulletsFactory::*)(const std::string &name) const;

#endif /* !BULLETSFACTORY_HPP_ */
