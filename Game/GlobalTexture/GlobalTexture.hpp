/*
** EPITECH PROJECT, 2021
** AAAAAAAAH
** File description:
** GlobalTexture
*/

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "AbsctractLibrary.hpp"
#ifndef GLOBALTEXTURE_HPP_
#define GLOBALTEXTURE_HPP_


namespace ne {
    class GlobalTexture : public ne::AbsctractLibrary<std::string, sf::Texture> {
        private:
            GlobalTexture();
            ~GlobalTexture() override = default;
        public:
            inline static ne::GlobalTexture& Instance()
            {
                static ne::GlobalTexture singleton;
                return (singleton);
            };
            void load(const std::string &) override;
    };
}

#endif /* !GLOBALTEXTURE_HPP_ */
