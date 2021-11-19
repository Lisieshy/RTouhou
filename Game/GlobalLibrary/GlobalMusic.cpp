/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GlobalMusic
*/

#include "GlobalMusic.hpp"

ne::GlobalMusic::GlobalMusic()
{
}

void ne::GlobalMusic::load(const std::string &path)
{
    if (_lib[path].openFromFile(path) == false)
        throw std::runtime_error ("Can't open file " + path);
}