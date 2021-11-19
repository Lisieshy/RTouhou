/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

/**
 * @file        main.cpp
 * @brief       Entrypoint.
 * @details     Contains the entrypoint of the program.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/2021
 */

// Pragma definition for Windows to remove the console window.
// #pragma comment(linker, "/SUBSYSTEM:windows")

#include <NekoEngine/NekoEngine.hpp>
#include <NekoEngine/Graphics/Window.hpp>
#include <random>
#include <chrono>
#include <sstream>

#include <NyaLog/NyaLog.hpp>
#include <include/CustomClient.hpp>
#include "../include/ClientGame.hpp"
#include "../../Game/Ennemies/EnnemiesFactory.hpp"
#include "../../Game/Bullets/BulletsFactory.hpp"
#include "../../Game/GameScene/GameScene.hpp"
#include "../../Game/GlobalTexture/GlobalTexture.hpp"

auto main(
    int argc,
    char** argv
) -> int
{
    nl::nyalog.setLogLevel(nl::LogLevel::Fatal);
    nl::nyalog.init();
    nl::nyalog(nl::LogLevel::Info, "R-Touhou! Configuring everything... Please wait!");

    std::vector<ne::EntityID> entities(10000);
    ne::ClientGame ClientGame;
    ne::Graphics::Window::open();

    int fps = 0;
    auto oldTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;
    while (!ne::Graphics::Window::shouldClose()) {
        fps++;
        auto startTime = std::chrono::high_resolution_clock::now();
        ne::Graphics::Window::pollEvent(ClientGame.ClientSystem);
        ne::Graphics::Window::clear(ne::Math::Vector4<unsigned char>{
            0, 0, 0, 255
        });
        ClientGame.ClientSystem->OnMessage();
        ClientGame.RenderSystem->update();
        ClientGame.PlayerSystem->update(dt);

        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::seconds{ 1 }) {
            std::string title = "R-Touhou | ";
            oldTime = std::chrono::high_resolution_clock::now();
            ne::Graphics::Window::setTitle(title.append(std::to_string(fps) + " fps"));
            fps = 0;
        }
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
    nl::nyalog(nl::LogLevel::Info, "Closing down...");
    ne::Graphics::Window::close();
    nl::nyalog.stop();
    return (0);
}