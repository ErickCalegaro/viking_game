/**
 * \file    keyboard.c
 * \version 0.0.1
 * \date    11/03/2024
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

static SDL_Scancode geLastKey;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/


/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret keyboard_HandleEvents(void)
{
    e_Ret eRet = RET_OK;
    static t_Velocity ptPlayerVelocity;
    ptPlayerVelocity.hEntityID = ghPlayerHandle;

    if (gtEvent.type == SDL_KEYDOWN)
    {
        geLastKey = gtEvent.key.keysym.scancode;
        switch (geLastKey)
        {
            case SDL_SCANCODE_W:
                ptPlayerVelocity.iVelocityY = -1;
                gtPlayerObject.tSprite.eAnimation = ANIM_WALK;
                break;
            case SDL_SCANCODE_A:
                ptPlayerVelocity.iVelocityX = -1;
                gtPlayerObject.tSprite.eAnimation = ANIM_WALK;
                break;
            case SDL_SCANCODE_S:
                ptPlayerVelocity.iVelocityY = 1;
                gtPlayerObject.tSprite.eAnimation = ANIM_WALK;
                break;
            case SDL_SCANCODE_D:
                ptPlayerVelocity.iVelocityX = 1;
                gtPlayerObject.tSprite.eAnimation = ANIM_WALK;
                break;
            default:
                break;
        }
    }

    if (gtEvent.type == SDL_KEYUP)
    {
        geLastKey = gtEvent.key.keysym.scancode;
        switch (geLastKey){
            case SDL_SCANCODE_W:
                ptPlayerVelocity.iVelocityY = 0;
                gtPlayerObject.tSprite.eAnimation = ANIM_IDLE;
                break;
            case SDL_SCANCODE_A:
                ptPlayerVelocity.iVelocityX = 0;
                gtPlayerObject.tSprite.eAnimation = ANIM_IDLE;
                break;
            case SDL_SCANCODE_S:
                ptPlayerVelocity.iVelocityY = 0;
                gtPlayerObject.tSprite.eAnimation = ANIM_IDLE;
                break;
            case SDL_SCANCODE_D:
                ptPlayerVelocity.iVelocityX = 0;
                gtPlayerObject.tSprite.eAnimation = ANIM_IDLE;
                break;
            default:
                break;
        }
    }
    
    if (geLastKey == SDL_SCANCODE_W ||
        geLastKey == SDL_SCANCODE_A ||
        geLastKey == SDL_SCANCODE_S ||
        geLastKey == SDL_SCANCODE_D ){
    
        eRet = entity_UpdateVelocity(&ptPlayerVelocity);
        if (eRet != RET_OK && eRet != RET_COLLISION){
            printf("Erro ao gerenciar velocidade!\n");
            return RET_POS_ERROR;
        }
    }

    return RET_OK;
}