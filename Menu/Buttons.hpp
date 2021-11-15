/*
** EPITECH PROJECT, 2021
** Buttons.hpp
** File description:
** Buttons.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BUTTONS_HPP
#define BUTTONS_HPP

namespace ne {
    class Buttons {
        public:
            Buttons(const std::string &name, const std::string &text, ne::Math::Vector2u pos);
            ~Buttons();

            ne::Transform getTransform();
            ne::Gravity getGravity();
            ne::RigidBody getRigidBody();
            ne::Color getColor();
            ne::Skin getSkin();
            ne::Scene getScene();
            std::shared_ptr<ne::PhysicsSystem> PhysicsSystem;
            std::shared_ptr<ne::RenderSystem> Rendering;
            std::string getName();

            std::string name;
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

#endif /* !BUTTONS_HPP */
