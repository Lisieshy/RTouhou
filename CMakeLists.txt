cmake_minimum_required(VERSION 3.17)

project(
    rtouhou
    VERSION 0.0.1
    DESCRIPTION "R-Touhou!"
    LANGUAGES CXX
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(NEKOENGINE_GRAPHICS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/Graphics/NekoWindowException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/Graphics/Window.cpp
)

set(NEKOENGINE_ECS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/EntityManager.cpp
)

set(NEKOENGINE_SYSTEMS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Systems/TimerSystem.cpp
)

set(NEKOENGINE_COMPONENTS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/NekoEngine/src/ECS/Components/Timer.cpp
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
)

set(SOURCES_CLIENT
    ${NEKOENGINE_SOURCES}
    ${PROJECT_SOURCES}
)

set(SOURCES_SERVER
    ${NEKOENGINE_SOURCES}
)

add_executable(rtouhou_client ${SOURCES_CLIENT})

target_compile_features(rtouhou_client PUBLIC cxx_std_17)

target_include_directories(rtouhou_client
    PRIVATE
    ${PROJECT_SOURCE_DIR}/NekoEngine/include
)

target_link_libraries(
    rtouhou_client
    ${CONAN_LIBS}
)

# add_executable(rtouhou_server ${SOURCES_SERVER})

# target_compile_features(rtouhou_server PUBLIC cxx_std_17)

# target_include_directories(rtouhou_server
#     PRIVATE
#     ${PROJECT_SOURCE_DIR}/include
# )
