/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Wave
*/

#include "Wave.hpp"

ne::Wave::Wave()
{
    time = 0.f;
}

ne::Wave::~Wave()
{
}

void ne::Wave::WaveLoop(float& dt, uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    static int i = 0;
    ne::Waves1 firstWave;

    time += dt;
    if (i == 0)
        firstWave.LaunchWaves(ID, coordinator);
    i = 1;
}