/*
** EPITECH PROJECT, 2021
** AAAAAAAAH
** File description:
** GlobalTexture
*/

/**
 * @file        GlobalTexture.hpp
 * @brief       Global library for texture loading
 * @author      Tom Wederich (@TheGorb) And Archo (@g_devoil)
 * @date        18/11/2021
 */

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "AbsctractLibrary.hpp"
#ifndef GLOBALTEXTURE_HPP_
#define GLOBALTEXTURE_HPP_


namespace ne {
    class GlobalTexture : public ne::AbsctractLibrary<std::string, sf::Texture> {
        private:
            /**
             * @brief Construct a new Global Texture object
             * 
             */
            GlobalTexture();

            /**
             * @brief Destroy the Global Texture object
             * 
             */
            ~GlobalTexture() override = default;
        public:
            /**
             * @brief
             * 
             * @return ne::GlobalTexture& 
             */
            inline static ne::GlobalTexture& Instance()
            {
                static ne::GlobalTexture singleton;
                return (singleton);
            };
            /**
             * @brief Load texture
             * 
             */
            void load(const std::string &) override;
    };
}

#endif /* !GLOBALTEXTURE_HPP_ */
