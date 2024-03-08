/**
 * \file    level_1.c
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

SDL_Texture * texture_Load(const char * psTexturePath, SDL_Renderer * ptRenderer)
{
    SDL_Surface *tTempSurface = IMG_Load(psTexturePath);
    if (tTempSurface == NULL) {
        printf("Não foi possivel carregar a imagem [%s]! SDL_Error: %s\n", psTexturePath, SDL_GetError());
        return NULL;
    }

    SDL_Texture *tLocalTexture = SDL_CreateTextureFromSurface(ptRenderer, tTempSurface);
    SDL_FreeSurface(tTempSurface);
    if (tLocalTexture == NULL) {
        printf("Não foi possivel criar a textura para [%s]! SDL_Error: %s\n", psTexturePath, SDL_GetError());
        return NULL;
    }

    return tLocalTexture;
}

