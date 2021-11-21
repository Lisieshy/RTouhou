/*
** EPITECH PROJECT, 2021
** Parallax.hpp
** File description:
** Parallax.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef PARALAX_HPP
#define PARALAX_HPP

/**
 * @namespace ne
 * 
 */
namespace ne {
    /**
     * @class Parallax
     * 
     */
    class Parallax {
        public:
            /**
             * @brief Construct a new Parallax object
             * 
             * @param pos Position of the parallax
             * @param path Path of the sprite
             */
            Parallax(ne::Math::Vector3f pos, std::string path);
            /**
             * @brief Destroy the Parallax object
             * 
             */
            ~Parallax();
            /**
             * @brief Get the Transform object
             * 
             * @return ne::Transform& 
             */
            ne::Transform& getTransform();
            /**
             * @brief Get the Skin object
             * 
             * @return ne::Skin& 
             */
            ne::Skin& getSkin();

            ne::Skin skin;
            ne::Transform transf;
        protected:
        private:
    };
}

#endif /* !PARALAX_HPP */
