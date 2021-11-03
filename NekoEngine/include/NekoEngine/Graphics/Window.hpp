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

// #include <NekoEngine/ECS/Components/Components.hpp>
#include <NekoEngine/Math/Vector/Vector.hpp>

/**
 * @namespace ne::Graphics::Window
 */
namespace ne::Graphics::Window {
    /**
     * @brief Is the windows open ?
     * @return true if the window is opened.
     * @return false if the window is not opened.
     */
    bool isOpen();

    void open();

    void close();

    /**
     * @brief Poll the window events.
     * This is where every event handling should be done.
     */
    void pollEvent();

    /**
     * @brief Display the window
     * You need to call this function at the end of the render loop for the window to be displayed.
     */
    void display();

    // /**
    //  * @brief Draw a rectangle.
    //  * 
    //  * @param transform The transform containing the rectangle's position, rotation and size.
    //  * @param color The color to draw the rectangle in.
    //  */
    // void drawRectangle(ne::Transform& transform, ne::Color& color);

    // void clear(ne::Math::Vector4f Color);
}

#endif /* !WINDOW_HPP_ */
