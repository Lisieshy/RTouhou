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

void ne::EnnemiesFactory::createEnnemies(const std::string &name)
{
    _create[name];
}

void ne::EnnemiesFactory::createBasicPlane(const std::string &name) const noexcept
{
    
}
