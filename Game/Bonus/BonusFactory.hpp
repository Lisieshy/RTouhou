/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BonusFactory
*/

#include "BonusType/BonusInclude.hpp"
#include "Bonus.hpp"

#ifndef BONUSFACTORY_HPP_
#define BONUSFACTORY_HPP_

namespace ne {
    class BonusFactory {
        public:
            BonusFactory();
            ~BonusFactory();

            std::unique_ptr<ne::Bonus> createBonus(const std::string &name);
        protected:
        private:
            std::map<std::string, std::unique_ptr<ne::Bonus>(ne::BonusFactory::*)(const std::string &name) const> _create;
            std::unique_ptr<ne::Bonus> createScoreUp(const std::string &name) const noexcept;
    };
}
using BonusFact = std::unique_ptr<ne::Bonus>(ne::BonusFactory::*)(const std::string &name) const;

#endif /* !BONUSFACTORY_HPP_ */
