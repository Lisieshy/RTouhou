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
            Setting(std::vector<ne::EntityID> entity);
            ~Setting();

            ne::Transform getTransform();
            ne::Skin getSkin();
            void InitScene();

            std::shared_ptr<ne::RenderSystem> Rendering;
            std::shared_ptr<ne::MouseSystem> MouseSys;
            std::shared_ptr<ne::TextSystem> TextSys;
            std::vector<ne::EntityID> entities;
            ne::Scene scene;
        protected:
        private:
    };
}

#endif /* !SETTING_HPP */
