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
#include <NekoEngine/ECS/Coordinator.hpp>
#include <NekoEngine/ECS/Components/Components.hpp>

/**
 * @namespace ne::Graphics
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

            /**
             * @brief Gets the window instance.
             * It's using the Singleton Deisgn Pattern to avoid the handling of multiple windows, and thus multiple renderers and event pollers.
             * @return Window&
             */
            auto static Get() -> Window&;

            /**
             * @brief Is the windows open ?
             * @return true if the window is opened.
             * @return false if the window is not opened.
             */
            bool isOpen() const;

            /**
             * @brief Poll the window events.
             * This is where every event handling should be done.
             */
            void pollEvent() const;

            /**
             * @brief Display the window
             * You need to call this function at the end of the render loop for the window to be displayed.
             */
            void display() const;

            /**
             * @brief Draw a rectangle.
             * 
             * @param transform The transform containing the rectangle's position, rotation and size.
             * @param color The color to draw the rectangle in.
             */
            void drawRectangle(ne::Transform& transform, ne::Color& color) const;

        private:
            /**
             * @brief The window constructor.
             */
            Window();

            /**
             * @brief The window destructor.
             */
            ~Window();

            struct WImpl;
            /**
             * @brief The window implementation.
             * Using the "Pointer to Implementation" (PImpl) idiom, this is the only way to access the window's implementation.
             * Using this technique makes it possible to use SFML's window module without having to include it in the header.
             */
            std::unique_ptr<WImpl> _wImpl;


    };
}

#endif /* !WINDOW_HPP_ */
