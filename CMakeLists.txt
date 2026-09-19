cmake_minimum_required(VERSION 3.16)

project(TermPlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TermPlusPlus
    src/main.cpp
    src/commands.cpp
    src/commands.hpp
    src/constants.hpp
    src/rpg.cpp
)
