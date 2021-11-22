cmake_minimum_required(VERSION 3.20)

project(
    rtouhou
    VERSION 0.0.1
    DESCRIPTION "R-Touhou!"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

find_package(Threads REQUIRED)

file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}/bin
)

set(NEKOENGINE_GRAPHICS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/Graphics/NekoWindowException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/Graphics/Window.cpp
)

set(NEKOENNEMIES_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/Ennemies.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesType/BasicPlane.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesType/DarkBlueFerry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesType/GreenFerry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesType/OrangeFerry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Ennemies/EnnemiesType/whiteFerry.cpp
)
set(NEKOGAME_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/GameScene/GameScene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/GameScene/GameEnnemiesLoop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/GlobalLibrary/GlobalTexture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/GlobalLibrary/GlobalSound.cpp
)

set(NEKOBULLETS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/Bullets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BasicWhiteBullets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BulletsTier2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BulletsTier3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/FriendlyBullets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BulletsPlT2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BulletsPlT3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsFactory.cpp
)

set(NEKOWAVES_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Waves/AWaves.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Waves/Wave.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Waves/WavesType/Waves1.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Waves/WavesType/Waves2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Waves/WavesType/Waves3.cpp
)

set(NEKOMENU_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Menu/Menu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Menu/Buttons.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Menu/Setting.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Menu/Text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Menu/Background.cpp
)

set(NEKOENGINE_ECS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/EntityManager.cpp
)

set(NEKOENGINE_SYSTEMS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/TimerSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/MouseSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/TextSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/PatternSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/BackgroundSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/AnimationSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/Collision.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/BonusSystem.cpp
)

set(NEKOBONUS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bonus/BonusType/ScoreUp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bonus/Bonus.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bonus/BonusFactory.cpp
)

set(NEKOENGINE_COMPONENTS_SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Components/Timer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Components/Patterns.cpp
)

set(NEKOENGINE_SCENES_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/Scenes/Scene.cpp
)

set(NEKOENGINE_NEKOEXCEPTION_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/NekoException/NekoException.cpp
)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/ClientGame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/ClientCollision.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/Sound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client/src/PlayerSystem.cpp
)

set(NEKOENGINE_SOURCES
    ${NEKOENGINE_GRAPHICS_SOURCES}
    ${NEKOENGINE_ECS_SOURCES}
    ${NEKOENGINE_SYSTEMS_SOURCES}
    ${NEKOENGINE_COMPONENTS_SOURCES}
    ${NEKOENGINE_SCENES_SOURCES}
    ${NEKOENGINE_NEKOEXCEPTION_SOURCES}
    ${NEKOENNEMIES_SOURCES}
    ${NEKOMENU_SOURCES}
    ${NEKOBULLETS_SOURCES}
    ${NEKOWAVES_SOURCES}
    ${NEKOGAME_SOURCES}
    ${NEKOBONUS_SOURCES}
)

set(SOURCES_CLIENT
    ${NEKOENGINE_SOURCES}
    ${PROJECT_SOURCES}
)

set(SOURCES_SERVER
    ${NEKOENGINE_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/src/main.cpp
)

add_executable(rtouhou_client ${SOURCES_CLIENT})

target_compile_features(rtouhou_client PRIVATE cxx_std_20)

target_include_directories(rtouhou_client
    PRIVATE
    ${PROJECT_SOURCE_DIR}/NekoEngine/include
    ${PROJECT_SOURCE_DIR}/Client/
    ${PROJECT_SOURCE_DIR}/NyaLog/
    ${PROJECT_SOURCE_DIR}/NyaNet/
    ${PROJECT_SOURCE_DIR}/Ennemies/
    ${PROJECT_SOURCE_DIR}/Menu/
    ${PROJECT_SOURCE_DIR}/Game/
)

target_link_libraries(
    rtouhou_client
    Threads::Threads
    ${CONAN_LIBS}
)

add_executable(rtouhou_server ${SOURCES_SERVER})

target_compile_features(rtouhou_server PRIVATE cxx_std_20)

target_include_directories(rtouhou_server
    PRIVATE
    ${PROJECT_SOURCE_DIR}/NekoEngine/include
    ${PROJECT_SOURCE_DIR}/Client/
    ${PROJECT_SOURCE_DIR}/NyaLog/
    ${PROJECT_SOURCE_DIR}/NyaNet/
)

target_link_libraries(
    rtouhou_server
    Threads::Threads
    ${CONAN_LIBS}
)