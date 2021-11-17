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
    _create["DarkBlue"] = &ne::EnnemiesFactory::createDarkBlueFerry;
    _create["GreenFerry"] = &ne::EnnemiesFactory::createGreenFerry;
    _create["OrangeFerry"] = &ne::EnnemiesFactory::createOrangeFerry;
    _create["WhiteFerry"] = &ne::EnnemiesFactory::createWhiteFerry;
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
    return (std::make_unique<ne::Ennemies>(BasicPlane()));
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createDarkBlueFerry(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Ennemies>(DarkBlueFerry()));
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createGreenFerry(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Ennemies>(GreenFerry()));
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createOrangeFerry(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Ennemies>(OrangeFerry()));
}

std::unique_ptr<ne::Ennemies> ne::EnnemiesFactory::createWhiteFerry(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Ennemies>(whiteFerry()));
}