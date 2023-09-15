cmake_minimum_required(VERSION 3.27)

project(HEXGAME_CPP)
set(CMAKE_CXX_STANDARD 14)   

# Add your source files here


file(GLOB SOURCES "HexGame.c++")

add_executable(HEXGAME_CPP ${SOURCES})