/**
 * \file    screen.c
 * \version 0.0.1
 * \date    07/03/2024
 * \author  Erick Calegaro
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "main.h"
#include "screen.h"

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/
const int SCREEN_WIDTH  = 1200;
const int SCREEN_HEIGHT = 600;

SDL_Renderer * tRenderer;
SDL_Window   * tWindow;

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/
e_Ret screen_CreateWindow(void) 
{
    char sTitle[] = APP_NAME " - " VERSION;
    
    if (TTF_Init() < 0) {
        printf("Fontes nao puderam ser inicializadas! TTF_Error: %s\n", TTF_GetError());
        return RET_INIT_ERROR;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL nao pode ser inicializado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    tWindow = SDL_CreateWindow(sTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (tWindow == NULL) {
        printf("Janela nao pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }
    
    tRenderer = SDL_CreateRenderer(tWindow, -1, SDL_RENDERER_ACCELERATED);
    if (tRenderer == NULL) {
        printf("Renderizador nao pode ser criado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    return RET_OK;
}