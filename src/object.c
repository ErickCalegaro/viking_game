/**
 * \file    object.c
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

e_Ret object_Create(t_GameObject * ptGameObject, const char * psTextureSheet, int iPosX, int iPosY)
{
    ptGameObject->ptTexture  = texture_Load(psTextureSheet);
    if (ptGameObject->ptTexture == NULL){
        printf("Não foi possivel criar a textura!\n");
        return RET_SDL_ERROR;
    }

    ptGameObject->iPosX = iPosX;
    ptGameObject->iPosY = iPosY;

    return RET_OK;
}

e_Ret object_Update(t_GameObject * ptGameObject, t_Position * ptPosition)
{
    ptGameObject->iPosX = ptPosition->iPosX;
    ptGameObject->iPosY = ptPosition->iPosY;

    ptGameObject->tSourceRect.h = 64;
    ptGameObject->tSourceRect.w = 64;
    ptGameObject->tSourceRect.x = 0;
    ptGameObject->tSourceRect.y = 0;
    
    ptGameObject->tDestRect.h = ptGameObject->tSourceRect.h;
    ptGameObject->tDestRect.w = ptGameObject->tSourceRect.w;
    ptGameObject->tDestRect.x = ptGameObject->iPosX;
    ptGameObject->tDestRect.y = ptGameObject->iPosY;

    return RET_OK;
}

e_Ret object_Render(t_GameObject * ptGameObject)
{
    e_Ret eRet = sprite_Render(ptGameObject);
    if (eRet != RET_OK) {
        printf("Nao foi possivel renderizar o sprite! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    return RET_OK;
}