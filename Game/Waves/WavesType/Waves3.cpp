/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Waves3
*/

#include "Waves3.hpp"

ne::Waves3::Waves3()
{
}

ne::Waves3::~Waves3()
{
}

void ne::Waves3::LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    ne::Waves1 wave1;
    ne::Waves2 wave2;

    wave1.LaunchWaves(ID, coordinator);
    wave2.LaunchWaves(ID, coordinator); 
}
