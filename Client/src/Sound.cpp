/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Sound
*/

#include "../include/Sound.hpp"

ne::Sound::Sound()
{
    Gun.loadFromFile("resources/Music_SoundEffect/piou.wav");
    BadGuy.loadFromFile("resources/Music_SoundEffect/pooouh.wav");
    Waves.loadFromFile("resources/Music_SoundEffect/bounga.wav");
    GunSound.setBuffer(Gun);
    BadGuySound.setBuffer(BadGuy);
    WavesSound.setBuffer(Waves);
}

ne::Sound::~Sound()
{
}
