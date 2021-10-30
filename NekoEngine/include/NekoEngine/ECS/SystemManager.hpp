/*
** EPITECH PROJECT, 2021
** SystemManager
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include <memory>
#include <map>
#include "NekoEngine/ECS/System.hpp"
#include "NekoEngine/ECS/Coordinator.hpp"

namespace ne {

    class SystemManager {
        public:
            template<typename T>
            std::shared_ptr<T> registerSystem(std::shared_ptr<ne::Coordinator> coordinator);

            template<typename T>
            void setSignature(Signature signature);
            void entityDestroyed(ne::EntityID entity);
            void entitySignatureChanged(ne::EntityID entity, Signature entitySignature);

        private:
            std::map<const char*, Signature> m_signatures{};
            std::map<const char*, std::shared_ptr<System>> m_systems{};
    };
}

#include "SystemManager.tpp"

#endif /* !SYSTEMMANAGER_HPP_ */
