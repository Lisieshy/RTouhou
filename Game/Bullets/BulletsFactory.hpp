/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsFactory
*/
#include "Bullets.hpp"
#include "BulletsType/BulletsTypeInclude.hpp"
#ifndef BULLETSFACTORY_HPP_
#define BULLETSFACTORY_HPP_

namespace ne {
    class BulletsFactory {
        public:
            BulletsFactory();
            ~BulletsFactory();
            std::unique_ptr<ne::Bullets> createBullets(const std::string &name);
        protected:
        private:
            std::map<std::string, std::unique_ptr<ne::Bullets>(ne::BulletsFactory::*)(const std::string &name) const> _create;
            std::unique_ptr<ne::Bullets> createBasicWhiteBullets(const std::string &name) const noexcept;
    };
}
using BulletsFact = std::unique_ptr<ne::Bullets>(ne::BulletsFactory::*)(const std::string &name) const;

#endif /* !BULLETSFACTORY_HPP_ */
