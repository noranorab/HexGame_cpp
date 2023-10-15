cmake_minimum_required(VERSION 3.27)

project(HEXGAME_CPP)
set(CMAKE_CXX_STANDARD 14)   

# Add your source files here


file(GLOB SOURCES "GraphicGame.c++")


# Specify the location of your SDL library and header files
set(SDL2_INCLUDE_DIR "C:/SDL2/include")  # Update this path
set(SDL2_LIBRARY "C:/SDL2/lib/x64/SDL2.lib")  # Update this path

# Include the SDL headers
include_directories(${SDL2_INCLUDE_DIR})

# Add your source files
#add_executable(HEXGAME_CPP GraphicGame.c++)
add_executable(HEXGAME_CPP ${SOURCES})

# Link against the SDL library
target_link_libraries(HEXGAME_CPP ${SDL2_LIBRARY})

