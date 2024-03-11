/**
 * \file    control.c
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

static bool gbIsRunning = false;
SDL_Event gtEvent;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/


/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

bool control_GetRunning(void)
{
    return gbIsRunning;
}

void control_SetRunning(bool bIsRunning)
{
    gbIsRunning = bIsRunning;
}

e_Ret control_HandleEvents(void)
{
    SDL_PollEvent(&gtEvent);
    switch (gtEvent.type)
    {
        case SDL_QUIT:
            control_SetRunning(false);
            printf("Encerrando o jogo!\n");
            return RET_ABORT;
        default:
            break;
    }

    return RET_OK;
}