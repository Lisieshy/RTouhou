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
#include "EnnemiesType/BasicPlane.hpp"
#ifndef ENNEMIESFACTORY_HPP_
#define ENNEMIESFACTORY_HPP_

namespace ne {
    class EnnemiesFactory {
        public:
            EnnemiesFactory();
            ~EnnemiesFactory();
            std::unique_ptr<ne::Ennemies> createEnnemies(const std::string &name);
        protected:
        private:
            std::map<std::string, std::unique_ptr<ne::Ennemies>(ne::EnnemiesFactory::*)(const std::string &name) const>  _create;
            std::unique_ptr<ne::Ennemies> createBasicPlane(const std::string &name) const noexcept;
    };
}
using fact = std::unique_ptr<ne::Ennemies>(ne::EnnemiesFactory::*)(const std::string &name) const;

#endif /* !ENNEMIESFACTORY_HPP_ */
