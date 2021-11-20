/*
** EPITECH PROJECT, 2021
** Text.hpp
** File description:
** Text.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef TEXT_HPP
#define TEXT_HPP

/**
 * @namespace ne
 * 
 */
namespace ne {
    /**
     * @class Text
     * 
     */
    class Text {
        public:
            /**
             * @brief Construct a new Text object
             * 
             * @param name Of the Text object
             * @param text Content of the text object
             * @param pos Position of the Text object
             */
            Text(const std::string &name, const std::string &text, ne::Math::Vector2u pos);
            /**
             * @brief Destroy the Text object
             * 
             */
            ~Text();

            /**
             * @brief Get the Text Info object
             * 
             * @return ne::Textinfo& 
             */
            ne::Textinfo& getTextInfo();
            /**
             * @brief Get the Transform object
             * 
             * @return ne::Transform& 
             */
            ne::Transform& getTransform();

            ne::Textinfo _textinfo;
            ne::Transform transf;
        protected:
        private:
    };
}

#endif /* !TEXT_HPP */
