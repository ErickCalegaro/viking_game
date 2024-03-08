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
#include "control.h"

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

static SDL_Renderer    *tRenderer;
static SDL_Window      *tWindow;
static int              giCount = 0;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

/**
 * \brief Pinta a tela com a cor de fundo default.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
static e_Ret screen_DrawBackground(void); 

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

static e_Ret screen_DrawBackground(void)
{
    e_Ret eRet = RET_OK;
    eRet = SDL_SetRenderDrawColor(tRenderer, 0, 255, 0, 255);
    if (eRet < 0) {
        printf("Nao foi possivel definir a cor de fundo! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    eRet = screen_Render();
    if (eRet < 0) {
        printf("Nao foi possivel renderizar a tela!\n");
        return RET_SDL_ERROR;
    }

    return eRet;
}

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret screen_InitSDL(void)
{ 
    if (TTF_Init() < 0) {
        printf("Fontes nao puderam ser inicializadas! TTF_Error: %s\n", TTF_GetError());
        return RET_INIT_ERROR;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL nao pode ser inicializado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    return RET_OK;
}

e_Ret screen_CreateWindow(bool bFullscreen) 
{
    char sTitle[] = APP_NAME " - " VERSION;
    int iFlags = SDL_WINDOW_SHOWN;
    
    if (bFullscreen){
        iFlags = SDL_WINDOW_FULLSCREEN;
    }

    tWindow = SDL_CreateWindow(sTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, iFlags);
    if (tWindow == NULL) {
        printf("Janela nao pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }
    
    tRenderer = SDL_CreateRenderer(tWindow, -1, 0);
    if (tRenderer == NULL) {
        printf("Renderizador nao pode ser criado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    if (screen_DrawBackground()) {
        printf("Nao foi possivel desenhar o BG!\n");
        return RET_INIT_ERROR;
    }

    return RET_OK;
}

e_Ret screen_Update(void)
{
    e_Ret eRet = RET_OK;
    giCount++;
    printf("giCount = [%d]\n", giCount);

    return eRet;
}

e_Ret screen_Render(void)
{
    e_Ret eRet = RET_OK;

    eRet = SDL_RenderClear(tRenderer);
    if (eRet < 0) {
        printf("Nao foi possivel limpar o render! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    SDL_RenderPresent(tRenderer); 

    return eRet;
}

e_Ret screen_DestroySDL(void)
{ 
    SDL_DestroyWindow(tWindow);

    SDL_DestroyRenderer(tRenderer);

    SDL_Quit();

    return RET_OK;
}