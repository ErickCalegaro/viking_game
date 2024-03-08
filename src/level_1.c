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

e_Ret level_1_Loop(e_State * eNextState)
{
    eNextState = eNextState; //Unref parameter
    
    e_Ret   eRet         = RET_OK;
    Uint32  uiFrameStart = 0;
    int     iFrameTime   = 0;

    do{
        uiFrameStart = SDL_GetTicks();

        control_HandleEvents();
        screen_Update();
        eRet = screen_Render();
        if (eRet){
            printf("Nao foi possivel renderizar a tela!\n");
            break;
        }
        
        iFrameTime = SDL_GetTicks() - uiFrameStart;

        if (FRAME_DELAY > iFrameTime){ //Trava de FPS
            SDL_Delay(FRAME_DELAY - iFrameTime);
        }
        
    } while (control_GetRunning());

    return RET_OK;
}
