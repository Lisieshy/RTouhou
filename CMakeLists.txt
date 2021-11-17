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

# file(COPY
#     ${CMAKE_CURRENT_SOURCE_DIR}/
#     DESTINATION
#     ${CMAKE_CURRENT_BINARY_DIR}/Assets/
# )

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
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/GlobalTexture/GlobalTexture.cpp
)

set(NEKOBULLETS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/Bullets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsType/BasicWhiteBullets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game/Bullets/BulletsFactory.cpp
)

set(NEKOENGINE_ECS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/EntityManager.cpp
)

set(NEKOENGINE_SYSTEMS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/TimerSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/PatternSystem.cpp
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
)

set(NEKOENGINE_SOURCES
    ${NEKOENGINE_GRAPHICS_SOURCES}
    ${NEKOENGINE_ECS_SOURCES}
    ${NEKOENGINE_SYSTEMS_SOURCES}
    ${NEKOENGINE_COMPONENTS_SOURCES}
    ${NEKOENGINE_SCENES_SOURCES}
    ${NEKOENGINE_NEKOEXCEPTION_SOURCES}
    ${NEKOENNEMIES_SOURCES}
    ${NEKOBULLETS_SOURCES}
    ${NEKOGAME_SOURCES}
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