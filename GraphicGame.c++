#include <SDL.h>



#include <iostream>


// Define screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    // Initialize SDL and create a window
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Check if the window was created successfully
    if (window == NULL) {
        // Handle window creation error
        return 2;
    }

    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Check if the renderer was created successfully
    if (renderer == NULL) {
        // Handle renderer creation error
        return 3;
    }

    // Game loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events and game logic here

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render game objects

        // Update the screen
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}