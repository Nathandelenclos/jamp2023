cmake_minimum_required(VERSION 3.26)
project(jam)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

include_directories(includes)
include_directories(${SFML_INCLUDE_DIR})

add_executable(jam src/main.cpp
        src/Game.cpp
        includes/Game.hpp
        src/Object.cpp
        includes/Object.hpp
        src/Text.cpp
        includes/Text.hpp
        src/Case.cpp
        includes/Case.hpp
        src/Engine.cpp
        includes/Engine.hpp
        src/Link.cpp
        includes/Link.hpp)

target_link_libraries(jam sfml-system sfml-window sfml-graphics sfml-audio)
