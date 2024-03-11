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
    t_Velocity ptPlayerVelocity = {0x00};
    ptPlayerVelocity.hEntityID = ghPlayerHandle;

    if (gtEvent.type == SDL_KEYDOWN)
    {
        switch (gtEvent.key.keysym.sym)
        {
            case SDLK_w:
                ptPlayerVelocity.iVelocityY = -1;
                break;
            case SDLK_a:
                ptPlayerVelocity.iVelocityX = -1;
                break;
            case SDLK_s:
                ptPlayerVelocity.iVelocityY = 1;
                break;
            case SDLK_d:
                ptPlayerVelocity.iVelocityX = 1;
                break;
            default:
                break;
        }
    }

    if (gtEvent.type == SDL_KEYUP)
    {
        switch (gtEvent.key.keysym.sym)
        {
            case SDLK_w:
                ptPlayerVelocity.iVelocityY = 0;
                break;
            case SDLK_a:
                ptPlayerVelocity.iVelocityX = 0;
                break;
            case SDLK_s:
                ptPlayerVelocity.iVelocityY = 0;
                break;
            case SDLK_d:
                ptPlayerVelocity.iVelocityX = 0;
                break;
            default:
                break;
        }
    }
    
    if (gtEvent.key.keysym.sym == SDLK_w ||
        gtEvent.key.keysym.sym == SDLK_a ||
        gtEvent.key.keysym.sym == SDLK_s ||
        gtEvent.key.keysym.sym == SDLK_d ){
    
        eRet = entity_UpdateVelocity(&ptPlayerVelocity);
        if (eRet){
            printf("Erro ao gerenciar velocidade!\n");
            return RET_POS_ERROR;
        }
    }

    return RET_OK;
}