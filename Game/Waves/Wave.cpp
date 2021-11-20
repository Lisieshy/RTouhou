/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Wave
*/

#include "Wave.hpp"

ne::Wave::Wave()
{
}

ne::Wave::~Wave()
{
}

void ne::Wave::WaveLoop(float& dt, uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{
    static int i = 0;

    if (i == 0) {
        firstWave.LaunchWaves(ID, coordinator);
        i = 1;
    } if (i == 1 && firstWave.IsWaveFinished(dt)) {
        secondWave.LaunchWaves(ID, coordinator);
        i = 2;
    }  if (i == 2 && secondWave.IsWaveFinished(dt)) {
        ThirdWave.LaunchWaves(ID, coordinator);
        i = 3;
    }
}