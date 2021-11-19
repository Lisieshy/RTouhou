/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** AWaves
*/

#include "AWaves.hpp"

ne::AWaves::AWaves()
{
}

ne::AWaves::~AWaves()
{
}

bool ne::AWaves::IsWaveFinished(float dt)
{
    WaveTime -= dt;
    std::cout << "WAVE TIME = " << WaveTime << std::endl;
    if (WaveTime <= 0)
        return true;
    return false;
}

void ne::AWaves::LaunchWaves(uint32_t& ID, std::shared_ptr<ne::Coordinator>& coordinator)
{

}