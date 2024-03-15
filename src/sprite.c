/**
 * \file    sprite.c
 * \version 0.0.1
 * \date    14/03/2024
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

e_Ret sprite_Animated(t_GameObject * ptGameObject)
{
    ptGameObject->tSourceRect.x = ptGameObject->tSourceRect.w * ((int)(SDL_GetTicks() / ptGameObject->tSprite.iSpeed) % ptGameObject->tSprite.iFrames);
    printf("PASSOU AQUI\n");
    int iRet = SDL_RenderCopy(gptRenderer, 
                                ptGameObject->ptTexture, 
                                &ptGameObject->tSourceRect, 
                                &ptGameObject->tDestRect);
    if (iRet < RET_OK) {
        printf("Nao foi possivel renderizar a textura animada! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    return RET_OK;
}


e_Ret sprite_Static(t_GameObject * ptGameObject)
{
    int iRet = SDL_RenderCopy(gptRenderer, 
                                ptGameObject->ptTexture, 
                                &ptGameObject->tSourceRect, 
                                &ptGameObject->tDestRect);
    if (iRet < RET_OK) {
        printf("Nao foi possivel renderizar a textura estatica! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    return RET_OK;
}

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret sprite_Render(t_GameObject * ptGameObject)
{
    e_Ret eRet = RET_OK;

    if (ptGameObject->tSprite.bAnimated){
        eRet = sprite_Animated(ptGameObject);
    }else{
        eRet = sprite_Static(ptGameObject);
    }

    if (eRet) {
        printf("Nao foi possivel renderizar o sprite! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }
    
    return RET_OK;
}