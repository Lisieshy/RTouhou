/*
** EPITECH PROJECT, 2021
** Window Class
** File description:
** Window Class Wrapper Header
*/

/**
 * @file        Window.hpp
 * @brief       Contains the NekoEngine Window class wrapper.
 * @details     This Window class acts as a wrapper of SFML Window and aim's to simplify a lot of stuff.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

/**
 * @namespace NekoEngine::Graphics
 */
namespace ne::Graphics {
    /**
     * @brief The window class.
     * @details This class is a wrapper of SFML's window module.
     * It's using the Service Locator pattern to get the window's instance.
     * @class Window
     * @author Aurélien Schulz (@Lisieshy)
     * @date 10/2021
     */
    class Window {
        public:
            /**
             * @brief Delete the copy constructor.
             */
            Window(
                const Window& other
            ) = delete;

            auto static Get() -> Window&;

            bool isOpen() const;

            void display() const;

        private:
            Window();
            ~Window();
            struct WImpl;
            std::unique_ptr<WImpl> _wImpl;


    };
}

#endif /* !WINDOW_HPP_ */
