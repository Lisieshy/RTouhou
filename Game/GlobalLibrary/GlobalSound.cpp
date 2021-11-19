/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GlobalSound
*/

#include "GlobalSound.hpp"

ne::GlobalSound::GlobalSound()
{
}

void ne::GlobalSound::load(const std::string &path)
{
    if (_lib[path].loadFromFile(path) == false)
        throw std::runtime_error ("Can't open file " + path);   
}
