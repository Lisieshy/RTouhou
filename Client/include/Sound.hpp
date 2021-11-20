/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Sound
*/
#include <SFML/Audio.hpp>
#ifndef SOUND_HPP_
#define SOUND_HPP_

namespace ne {
    class Sound {
        public:
            Sound();
            ~Sound();

            sf::SoundBuffer Gun;
            sf::SoundBuffer BadGuy;
            sf::SoundBuffer Waves;
            sf::Sound GunSound;
            sf::Sound BadGuySound;
            sf::Sound WavesSound;
        protected:
        private:
    };
}

#endif /* !SOUND_HPP_ */
