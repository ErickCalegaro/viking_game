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
    SDL_Event tEvent;
    SDL_PollEvent(&tEvent);
    switch (tEvent.type)
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

//Temp test only
e_Ret control_TestMove(void)
{
    e_Ret eRet = RET_OK;

    //Posição do player
    eRet = vector_Add(ghPlayerHandle, 5, 0);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    //Posição do inimigo
    eRet = vector_Subtract(ghEnemyHandle, 5, 0);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}