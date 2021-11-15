/*
** EPITECH PROJECT, 2021
** Menu.hpp
** File description:
** Menu.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef MENU_HPP
#define MENU_HPP

namespace ne {
    class Menu {
        public:
            Menu();
            ~Menu();

            ne::Transform getTransform();
            ne::Gravity getGravity();
            ne::RigidBody getRigidBody();
            ne::Color getColor();
            ne::Skin getSkin();
            
            ne::Transform transf;
            ne::Gravity grav;
            ne::RigidBody rigid;
            ne::Renderable render;
            ne::Color temp;
            ne::Skin skin;
        protected:
        private:
    };
}
#endif /* !MENU_HPP */
