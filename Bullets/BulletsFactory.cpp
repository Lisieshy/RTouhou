/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** BulletsFactory
*/

#include "BulletsFactory.hpp"

ne::BulletsFactory::BulletsFactory()
{
    _create["BasicWhiteBullets"] = &ne::BulletsFactory::createBasicWhiteBullets;
}

ne::BulletsFactory::~BulletsFactory()
{
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBullets(const std::string &name)
{
    fact ptr;

    ptr = _create[name];
    return (this->*ptr)(name);
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBasicWhiteBullets(const std::string &name) const noexcept
{
    return ((std::unique_ptr<ne::Bullets>)new BasicWhiteBullets());
}