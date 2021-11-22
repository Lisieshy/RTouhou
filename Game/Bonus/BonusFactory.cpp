/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BonusFactory
*/

#include "BonusFactory.hpp"

ne::BonusFactory::BonusFactory()
{
    _create["ScoreUp"] = &ne::BonusFactory::createScoreUp;

}

ne::BonusFactory::~BonusFactory()
{
}

std::unique_ptr<ne::Bonus> ne::BonusFactory::createBonus(const std::string &name)
{
    BonusFact ptr;

    ptr = _create[name];
    return (this->*ptr)(name);
}

std::unique_ptr<ne::Bonus> ne::BonusFactory::createScoreUp(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bonus>(ScoreUp()));
}