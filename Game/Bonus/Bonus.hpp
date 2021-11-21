/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Bonus
*/

#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include "../GlobalLibrary/GlobalTexture.hpp"
#include <../NekoEngine/include/NekoEngine/ECS/Components/Components.hpp>
#include <../NekoEngine/include/NekoEngine/Math/Vector/Vector.hpp>

#ifndef BONUS_HPP_
#define BONUS_HPP_

namespace ne {
    class Bonus {
        public:
            Bonus();
            ~Bonus();

            ne::Transform& getTransform();

            ne::Skin &getSkin();

            ne::Patterns& getPattern();

            ne::EntityType::Type& getType();

            void setTransform(ne::Transform trans);

            void setSkin(ne::Skin skin);

            void setPattern(std::function<ne::Math::Vector3f()>);

            void setType(ne::EntityType::Type newType);
        protected:
        private:
            ne::Transform transform;
            ne::Skin skin;
            ne::Patterns pat;
            ne::EntityType::Type Type;
    };
}

#endif /* !BONUS_HPP_ */
