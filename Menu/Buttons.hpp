/*
** EPITECH PROJECT, 2021
** Buttons.hpp
** File description:
** Buttons.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef BUTTONS_HPP
#define BUTTONS_HPP

/**
 * @namespace ne
 */

namespace ne {
    class Buttons {
        public:
            /**
             * @brief Constructor
             * @param name Name of the button
             * @param text Text of the button
             * @param pos Position of the button
             */
            Buttons(const std::string &name, const std::string &text, ne::Math::Vector2u pos, ne::Math::Vector4u rect);
            
            /**
             * @brief Destructor
             */
            ~Buttons();

            /**
             * @brief getTransform
             */
            ne::Transform getTransform();
            ne::Gravity getGravity();
            ne::RigidBody getRigidBody();
            ne::Color getColor();
            ne::Skin getSkin();
            ne::Scene getScene();
            void setState(bool state);
            std::shared_ptr<ne::RenderSystem> Rendering;
            std::string getName();

            ne::Math::Vector4u _rect;
            std::string _text;
            ne::Transform transf;
            std::string name;
            ne::Skin skin;
            ne::Scene scene;
        protected:
        private:
    };
}

#endif /* !BUTTONS_HPP */
