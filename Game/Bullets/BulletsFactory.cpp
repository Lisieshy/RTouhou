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
    _create["Tier2Bullets"] = &ne::BulletsFactory::createTier2Bullets;
    _create["Tier3Bullets"] = &ne::BulletsFactory::createTier3Bullets;
    _create["FriendlyBullets"] = &ne::BulletsFactory::createFriendlyBullets;
    _create["BulletsPlT2"] = &ne::BulletsFactory::createBulletsPlT2;
    _create["BulletsPlT3"] = &ne::BulletsFactory::createBulletsPlT3;
}

ne::BulletsFactory::~BulletsFactory()
{
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBullets(const std::string &name)
{
    BulletsFact ptr;

    ptr = _create[name];
    return (this->*ptr)(name);
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBasicWhiteBullets(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(BasicWhiteBullets()));
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createTier2Bullets(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(BulletsTier2()));
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createTier3Bullets(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(BulletsTier3()));
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createFriendlyBullets(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(FriendlyBullets()));
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBulletsPlT2(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(BulletsPlT2()));
}

std::unique_ptr<ne::Bullets> ne::BulletsFactory::createBulletsPlT3(const std::string &name) const noexcept
{
    return (std::make_unique<ne::Bullets>(BulletsPlT3()));
}
