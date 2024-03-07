#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"

const int SCREEN_WIDTH  = 1200;
const int SCREEN_HEIGHT = 600;

SDL_Renderer * renderer;
SDL_Window   * window;

int screen_CreateWindow(void) 
{
    TTF_Init();
    char title[] = APP_NAME " - " VERSION;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 3;
    }

    return 0;
}