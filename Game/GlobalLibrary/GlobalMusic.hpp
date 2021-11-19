/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** GlobalMusic
*/

/**
 * @file        GlobalMusic.hpp
 * @brief       Global library for music loading
 * @author      Tom Wederich (@TheGorb)
 * @date        19/11/2021
 */

#ifndef GLOBALMUSIC_HPP_
#define GLOBALMUSIC_HPP_

#include <SFML/Audio.hpp>
#include <unordered_map>
#include "AbsctractLibrary.hpp"

namespace ne {
    class GlobalMusic : public ne::AbsctractLibrary<std::string, sf::Music> {
        private:
            /**
             * @brief Construct a new Global Music object
             * 
             */
            GlobalMusic();

            /**
             * @brief Destroy the Global Music object
             * 
             */
            ~GlobalMusic() override = default;
        public:
            /**
             * @brief 
             * 
             * @return ne::GlobalMusic& 
             */
            inline static ne::GlobalMusic& Instance()
            {
                static ne::GlobalMusic singleton;
                return (singleton);
            };

            /**
             * @brief Load Music
             * 
             */
            void load(const std::string &) override;
        protected:
        private:
    };
}

#endif /* !GLOBALMUSIC_HPP_ */
