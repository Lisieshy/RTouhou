/*
** EPITECH PROJECT, 2021
** Menu.hpp
** File description:
** Menu.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef MENU_HPP
#define MENU_HPP

/**
 * @namespace ne
 * 
 */
namespace ne {
    /**
     * @class Menu
     * 
     */
    class Menu {
        public:
            /**
             * @brief Construct a new Menu object
             * 
             * @param entities Number of entities
             */
            Menu(std::vector<ne::EntityID> entities);
            /**
             * @brief Destroy the Menu object
             */
            ~Menu();

            std::shared_ptr<ne::BackgroundSystem> RenderBackground;
            std::shared_ptr<ne::RenderSystem> Rendering;
            std::shared_ptr<ne::MouseSystem> MouseSys;            
        protected:
        private:
    };
}
#endif /* !MENU_HPP */
