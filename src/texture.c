/**
 * \file    texture.c
 * \version 0.0.1
 * \date    08/03/2024
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


/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/


/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/


/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

SDL_Texture * texture_Load(const char * psTexturePath)
{
    SDL_Surface *ptTempSurface = IMG_Load(psTexturePath);
    if (ptTempSurface == NULL) {
        printf("Não foi possivel carregar a imagem [%s]! SDL_Error: %s\n", psTexturePath, SDL_GetError());
        return NULL;
    }

    SDL_Texture *ptLocalTexture = SDL_CreateTextureFromSurface(gptRenderer, ptTempSurface);
    SDL_FreeSurface(ptTempSurface);
    if (ptLocalTexture == NULL) {
        printf("Não foi possivel criar a textura para [%s]! SDL_Error: %s\n", psTexturePath, SDL_GetError());
        return NULL;
    }

    return ptLocalTexture;
}

e_Ret texture_Draw(SDL_Texture *ptTexture, SDL_Rect tSourceRect, SDL_Rect tDestRect)
{
    e_Ret eRet = SDL_RenderCopy(gptRenderer, 
                                ptTexture, 
                                &tSourceRect, 
                                &tDestRect);
    if (eRet < RET_OK) {
        printf("Nao foi possivel renderizar a textura! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    return RET_OK;
}