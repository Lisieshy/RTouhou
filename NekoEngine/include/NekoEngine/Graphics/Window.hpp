/*
** EPITECH PROJECT, 2021
** Window Class
** File description:
** Window Class Wrapper Header
*/

/**
 * @file        Window.hpp
 * @brief       Contains the NekoEngine Window class wrapper.
 * @details     The "Not a Singleton but actually kinda like one but it's not pattern".
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "NekoEngine/ECS/Components/Components.hpp"
#include "NekoEngine/Math/Vector/Vector.hpp"
#include <include/CustomClient.hpp>

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

    /**
     * @brief Should the window be closed ?
     * @return True or False.
     */
    bool shouldClose();

    /**
     * @brief Open the window.
     * @details This function constructs the inner workings of the window.
     * This should be called at the beginning of the main loop.
     * Calling this function again will close and reopen the window.
     */
    void open();

    /**
     * @brief Close the window.
     * @details This function destroys the inner pointers of the window.
     */
    void close();

    /**
     * @brief Poll the window events.
     * This is where every event handling should be done.
     */
    void pollEvent(rt::CustomClient &client);

    /**
     * @brief Display the window
     * You need to call this function at the end of the render loop for the window to be displayed.
     */
    void display();

    /**
     * @brief Sets the window title.
     * @param title The title of the window.
     */
    void setTitle(std::string& title);

    /**
     * @brief Draw a rectangle.
     * 
     * @param transform The transform containing the rectangle's position, rotation and size.
     * @param color The color to draw the rectangle in.
     */
    void drawRectangle(ne::Transform& transform, ne::Color& color);

    /**
     * @brief Clears the window with a given RGBa color.
     * @details Since this function takes a ne::Vector4<unsigned char>, with RGBa being XYZw respectively.
     * @param color A vector containing the colors.
     */
    void clear(ne::Math::Vector4<unsigned char> color);
}

#endif /* !WINDOW_HPP_ */
