/*
** EPITECH PROJECT, 2021
** Text.hpp
** File description:
** Text.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef TEXT_HPP
#define TEXT_HPP

namespace ne {
    class Text {
        public:
            Text(const std::string &name, const std::string &text, ne::Math::Vector2u pos);
            ~Text();

            ne::Color getColor();
            std::shared_ptr<ne::RenderSystem> Rendering;
            ne::Textinfo getTextInfo();

            ne::Textinfo _textinfo;
        protected:
        private:
    };
}

#endif /* !TEXT_HPP */
