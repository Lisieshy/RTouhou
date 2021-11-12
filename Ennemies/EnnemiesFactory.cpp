/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** EnnemiesFactory
*/

#include "EnnemiesFactory.hpp"

ne::EnnemiesFactory::EnnemiesFactory()
{
    _create["BasicPlane"] = &ne::EnnemiesFactory::createBasicPlane;
}

ne::EnnemiesFactory::~EnnemiesFactory()
{
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createEnnemies(const std::string &name)
{
    fact ptr;

    ptr = _create[name];
    return (this->*ptr)(name);
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createBasicPlane(const std::string &name) const noexcept
{
    return ((std::unique_ptr<ne::Ennemies>)new BasicPlane());
}
