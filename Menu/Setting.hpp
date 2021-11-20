/*
** EPITECH PROJECT, 2021
** Setting.hpp
** File description:
** Setting.hpp
*/
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"

#ifndef SETTING_HPP
#define SETTING_HPP

namespace ne {
    class Setting {
        public:
            Setting(std::vector<ne::EntityID> entities);
            ~Setting();

            std::shared_ptr<ne::BackgroundSystem> RenderBackground;
            std::shared_ptr<ne::RenderSystem> Rendering;
            std::shared_ptr<ne::MouseSystem> MouseSys;
        protected:
        private:
    };
}

#endif /* !SETTING_HPP */
