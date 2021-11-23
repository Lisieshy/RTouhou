/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GlobalSound
*/

/**
 * @file        GlobalTexture.hpp
 * @brief       Global library for Sound loading
 * @author      Tom Wederich (@TheGorb)
 * @date        19/11/2021
 */

#include <SFML/Audio.hpp>
#include <unordered_map>
#include "AbsctractLibrary.hpp"
#ifndef GLOBALSOUND_HPP_
#define GLOBALSOUND_HPP_

namespace ne {
    class GlobalSound : public ne::AbsctractLibrary<std::string, sf::Font> {
        private:
            /**
             * @brief Construct a new Global Sound object
             * 
             */
            GlobalSound();

            /**
             * @brief Destroy the Global Sound object
             * 
             */
            ~GlobalSound() override = default;
        public:
            /**
             * @brief return instance of Sound
             * 
             * @return ne::GlobalSound& 
             */
            inline static ne::GlobalSound &Instance()
            {
                static ne::GlobalSound singleton;
                return (singleton);
            };

            /**
             * @brief Loader
             * 
             */
            void load(const std::string &) override;
        protected:
    };
}

#endif /* !GLOBALSOUND_HPP_ */
