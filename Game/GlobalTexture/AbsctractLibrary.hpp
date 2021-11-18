/*
** EPITECH PROJECT, 2021
** B-CPP-501-NCY-5-1-rtype-aurelien.schulz
** File description:
** AbsctractLibrary
*/

/**
 * @file        AbsctractLibrary.hpp
 * @brief       Abstract library to load only one time eact texture
 * @author      Tom Wederich (@TheGorb) And Archo (@g_devoil)
 * @date        18/11/2021
 */

#include <unordered_map>
#include <SFML/Graphics.hpp>

#ifndef ABSCTRACTLIBRARY_HPP_
#define ABSCTRACTLIBRARY_HPP_

namespace ne {
    template<typename Key, typename Data>
    class AbsctractLibrary {
        protected:
            std::unordered_map<Key, Data> _lib;
        public:
            AbsctractLibrary() = default;
            virtual ~AbsctractLibrary() = 0;

            const Data &GetData(const Key& name)
            {
                if (_lib.find(name) == _lib.end())
                    load(name);
                return _lib.find(name)->second;
            }
            void clear()
            {
                for (auto &c : _lib)
                    unload(c.first);
                _lib.clear();
            }
            virtual void unload(const Key&) {};
            virtual void load(const Key&) = 0;
        private:
    };
}
template<typename Key, typename Data>
ne::AbsctractLibrary<Key, Data>::~AbsctractLibrary()
{
    clear();
}

#endif /* !ABSCTRACTLIBRARY_HPP_ */
