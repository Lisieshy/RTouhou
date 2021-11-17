/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** EnnemiesFactory
*/
#include <memory>
#include <map>
#include <exception>
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include "Ennemies.hpp"
#include "EnnemiesType/EnnemiesTypeInclude.hpp"

#ifndef ENNEMIESFACTORY_HPP_
#define ENNEMIESFACTORY_HPP_

/**
 * @namespace ne
 * 
 */
namespace ne {
    class EnnemiesFactory {
        public:
            /**
             * @brief Construct a new Ennemies Factory object
             * 
             */
            EnnemiesFactory();

            /**
             * @brief Destroy the Ennemies Factory object
             * 
             */
            ~EnnemiesFactory();

            /**
             * @brief Create a Ennemies object
             * 
             * @param std::string 
             * @return std::unique_ptr<ne::Ennemies> 
             */
            std::unique_ptr<ne::Ennemies> createEnnemies(const std::string &name);
        protected:
        private:
            std::map<std::string, std::unique_ptr<ne::Ennemies>(ne::EnnemiesFactory::*)(const std::string &name) const>  _create;
            std::unique_ptr<ne::Ennemies> createBasicPlane(const std::string &name) const noexcept;
            std::unique_ptr<ne::Ennemies> createDarkBlueFerry(const std::string &name) const noexcept;
            std::unique_ptr<ne::Ennemies> createGreenFerry(const std::string &name) const noexcept;
            std::unique_ptr<ne::Ennemies> createOrangeFerry(const std::string &name) const noexcept;
            std::unique_ptr<ne::Ennemies> createWhiteFerry(const std::string &name) const noexcept;
    };
}
using fact = std::unique_ptr<ne::Ennemies>(ne::EnnemiesFactory::*)(const std::string &name) const;

#endif /* !ENNEMIESFACTORY_HPP_ */
