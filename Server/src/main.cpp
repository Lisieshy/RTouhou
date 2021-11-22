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
 * @date        07/11/2021
 */

#include <random>
#include <chrono>
#include <sstream>
#include <iostream>
#include <NekoEngine/NekoEngine.hpp>
#include <NyaNet/NyaNet.hpp>
#include <NyaLog/NyaLog.hpp>
#include "../../Game/Ennemies/EnnemiesFactory.hpp"
#include "../../Game/GameScene/GameScene.hpp"

auto main(
    int argc,
    char **argv
) -> int {
    nl::nyalog.setFilename("Server.log");
    nl::nyalog.setLogLevel(nl::LogLevel::Fatal);
    nl::nyalog.init();
    uint32_t entityID = 200;

    std::vector<ne::EntityID> entities(50000);
    ne::GameScene Game(entities);
    ne::EnnemiesFactory fact;
    Game.InitScene(entityID);

    Game.NetworkSystem->Start();
    Game.NetworkSystem->ID = entityID;

    auto oldTime = std::chrono::high_resolution_clock::now();
    auto beginTime = std::chrono::high_resolution_clock::now();
    float dt = 0.0f;
    int fps = 0;
    float timePassed = 0.0f;
    bool started = false;

    while (1) {
        if (Game.NetworkSystem->nIDCounter > static_cast<uint32_t>(10000)) {
            auto startTime = std::chrono::high_resolution_clock::now();
            fps++;
            if ((timePassed += dt) >= 0.001f) {
                Game.GameLoop(dt, entityID);
                Game.BonusSystem->update(dt, entityID);
                Game.EnnemiesLoopSystem->update(dt, entityID);
                Game.PatternSystem->update(dt);
                Game.CollisionSystem->update();
                if (Game.NetworkSystem->ID > entityID)
                    entityID = Game.NetworkSystem->ID;
                else
                    Game.NetworkSystem->ID = entityID;
            }
            else {
                std::cout << "";
            }
            if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::milliseconds{ 20 }) {
                oldTime = std::chrono::high_resolution_clock::now();
                Game.NetworkSystem->SendDataToClients();
                fps = 0;
            }
            auto stopTime = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
        }
        Game.NetworkSystem->Update(-1, false);

    }
    Game.NetworkSystem->Stop();

    nl::nyalog.stop();
    return 0;
}