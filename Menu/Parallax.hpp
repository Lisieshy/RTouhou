/*
** EPITECH PROJECT, 2021
** Parallax.hpp
** File description:
** Parallax.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef PARALAX_HPP
#define PARALAX_HPP

namespace ne {
    class Parallax {
        public:
            Parallax(ne::Math::Vector3f pos, std::string path);
            ~Parallax();
            ne::Transform& getTransform();
            ne::Skin& getSkin();

            ne::Skin skin;
            ne::Transform transf;
        protected:
        private:
    };
}

#endif /* !PARALAX_HPP */
