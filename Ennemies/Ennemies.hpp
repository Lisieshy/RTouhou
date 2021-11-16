/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** Ennemies
*/
#include "HitPoint.hpp"
#include "../NekoEngine/include/NekoEngine/NekoEngine.hpp"
#include <../NekoEngine/include/NekoEngine/Math/Vector/Vector.hpp>
#include <functional>

#ifndef ENNEMIES_HPP_
#define ENNEMIES_HPP_

namespace ne {
    class Ennemies {
        public:
            Ennemies();
            ~Ennemies();

            ne::HitPoint getHitPoint();

            ne::Transform getTransform();

            ne::Gravity getGravity();

            ne::RigidBody getRigidBody();

            ne::Color getColor();

            ne::Skin getSkin();

            ne::Patterns& getPattern();

            void setSkin();
            void setPattern(std::function<ne::Math::Vector3f()>);

            ne::HitPoint hp;
            ne::Transform trans;
            ne::Gravity grav;
            ne::RigidBody rigid;
            ne::Renderable render;
            ne::Color temp;
            ne::Skin skin;
            ne::Hostile hostile;
        protected:
        private:
            ne::Patterns pat;
    };
}

#endif /* !ENNEMIES_HPP_ */
