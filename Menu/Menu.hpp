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
            Menu(std::vector<ne::EntityID> entity);
            ~Menu();

            ne::Transform getTransform();
            ne::Gravity getGravity();
            ne::RigidBody getRigidBody();
            ne::Color getColor();
            ne::Skin getSkin();
            ne::Scene getScene();
            std::shared_ptr<ne::PhysicsSystem> PhysicsSystem;
            std::shared_ptr<ne::RenderSystem> Rendering;

            std::vector<ne::EntityID> entities;
            ne::Transform transf;
            ne::Gravity grav;
            ne::RigidBody rigid;
            ne::Renderable render;
            ne::Color temp;
            ne::Skin skin;
            ne::Scene scene;
        protected:
        private:
    };
}
#endif /* !MENU_HPP */
