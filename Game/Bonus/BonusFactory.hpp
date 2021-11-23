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
            /**
             * @brief Construct a new Bonus Factory object
             * 
             */
            BonusFactory();

            /**
             * @brief Destroy the Bonus Factory object
             * 
             */
            ~BonusFactory();

            /**
             * @brief Create a Bonus object
             * 
             * @param const std::string 
             * @return std::unique_ptr<ne::Bonus> 
             */
            std::unique_ptr<ne::Bonus> createBonus(const std::string &name);
        protected:
        private:
            std::map<std::string, std::unique_ptr<ne::Bonus>(ne::BonusFactory::*)(const std::string &name) const> _create;

            /**
             * @brief Create a Score Up object
             * 
             * @param const std::string 
             * @return std::unique_ptr<ne::Bonus> 
             */
            std::unique_ptr<ne::Bonus> createScoreUp(const std::string &name) const noexcept;
    };
}
using BonusFact = std::unique_ptr<ne::Bonus>(ne::BonusFactory::*)(const std::string &name) const;

#endif /* !BONUSFACTORY_HPP_ */
