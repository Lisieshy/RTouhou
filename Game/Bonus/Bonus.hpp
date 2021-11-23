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
            /**
             * @brief Construct a new Bonus object
             * 
             */
            Bonus();

            /**
             * @brief Destroy the Bonus object
             * 
             */
            ~Bonus();

            /**
             * @brief Get the Transform object
             * 
             * @return ne::Transform& 
             */
            ne::Transform& getTransform();

            /**
             * @brief Get the Skin object
             * 
             * @return ne::Skin& 
             */
            ne::Skin &getSkin();

            /**
             * @brief Get the Pattern object
             * 
             * @return ne::Patterns& 
             */
            ne::Patterns& getPattern();

            /**
             * @brief Get the Type object
             * 
             * @return ne::EntityType::Type& 
             */
            ne::EntityType::Type& getType();

            /**
             * @brief Set the Transform object
             * 
             * @param ne::Transform 
             */
            void setTransform(ne::Transform trans);

            /**
             * @brief Set the Skin object
             * 
             * @param ne::Skin 
             */
            void setSkin(ne::Skin skin);

            /**
             * @brief Set the Pattern object
             * 
             * @param std::function<ne::Math::Vector3f()>
             */
            void setPattern(std::function<ne::Math::Vector3f()>);

            /**
             * @brief Set the Type object
             * 
             * @param ne::EntityType::Type 
             */
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
