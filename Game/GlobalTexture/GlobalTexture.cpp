/*
** EPITECH PROJECT, 2021
** AAAAAAAAH
** File description:
** GlobalTexture
*/

#include "GlobalTexture.hpp"

ne::GlobalTexture::GlobalTexture()
{

}

void ne::GlobalTexture::load(const std::string &path)
{
    if (_lib[path].loadFromFile(path) == false)
        throw std::runtime_error ("Can't open file " + path);   
}
