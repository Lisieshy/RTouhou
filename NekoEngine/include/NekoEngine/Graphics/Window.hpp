/*
** EPITECH PROJECT, 2021
** Window Class
** File description:
** Window Class Wrapper Header
*/

/**
 * @file        Window.hpp
 * @brief       Contains the NekoEngine Window class wrapper of raylib.
 * @details     This Window class acts as a wrapper of raylib's core module and aim's to simplify a lot of stuff.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <memory>
#include <SFML/Window.hpp>

/**
 * @namespace NekoEngine::Graphics
 */
namespace ne::Graphics {
    /**
     * @brief The window class.
     * @details This class is a wrapper of SFML's window module.
     * @class Window
     * @author Aurélien Schulz (@Lisieshy)
     * @date 05/21/2021
     */
    class Window {
        private:
            std::unique_ptr<sf::Window> _window;
    }
}
//     /**
//      * @brief NekoEngine Window Class wrapper.
//      */
//     class Window {
//         public:
//             /**
//              * @brief Gets the window.
//              * Will throw a ne::NekoWindowException if an error occurs.
//              * @return Window singleton
//              */
//             static Window &Get();

//             /**
//              * @brief Copy constructor removed to avoid singleton duplication
//              */
//             Window(const Window&) = delete;

//             /**
//              * @brief Function that tells you if the window has received a closing event
//              *
//              * @return true or false if the window should close or not
//              */
//             bool shouldClose();

//             /**
//              * @brief Define basics settings of your window.
//              *
//              * @param title The name of the window
//              * @param width The width of the window
//              * @param height The height of the window
//              * @param isResizable Should the window let the user resize it?
//              * @param isFullscreen Should the window be in fullscreen ?
//              */
//             void defineWindow(std::string const& title, int width, int height, bool isResizable, bool isFullscreen);

//             int getScreenWidth(void);

//             int getScreenHeight(void);

//             void setScreenFramerate(int frameRate);

//             void StartDrawing(void);

//             void EndDrawing(void);

//             void Clear(ne::Color color);

//             bool isOpen = true;
//             int menu = 0;
//             Music music;
//             float volume = 1.0f;
//         private:
//             Window();
//             ~Window();
//             bool isReady(void);
//             bool isFullscreen(void);
//             bool isHidden(void);
//             bool isMinimized(void);
//             bool isMaximized(void);
//             bool isFocused(void);
//             bool isResized(void);
//             bool isState(unsigned int flag);
//             void setState(unsigned int flags);
//             void clearState(unsigned int flags);
//             void toggleFullscreen(void);
//             void maximize(void);
//             void minimize(void);
//             void restore(void);
//             //void setIcon(Image image);
//             void setTitle(std::string title);
//             void setPosition(int x, int y);
//             void setMonitor(int monitor);
//             void setMinSize(int width, int height);
//             void setSize(int width, int height);
//             void *getHandle(void);
//             int getMonitorCount(void);
//             int getCurrentMonitor(void);
//             Vector2<float> getMonitorPosition(int monitor);
//             int getMonitorWidth(int monitor);
//             int getMonitorHeight(int monitor);
//             int getMonitorPhysicalWidth(int monitor);
//             int getMonitorPhysicalHeight(int monitor);
//             int getMonitorRefreshRate(int monitor);
//             Vector2<float> getPosition(void);
//             Vector2<float> getScaleDPI(void);
//             std::string getMonitorName(int monitor);
//             void setClipboardText(std::string text);
//             std::string getClipboardText(void);

//             int width = 0;

//             int height = 0;
//     };
// }

#endif /* !WINDOW_HPP_ */
