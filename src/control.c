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

static bool gbIsRunning = FALSE;

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
            control_SetRunning(FALSE);
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
    t_Position tTempPosition;

    //Posição do jogador
    tTempPosition.hEntityID = ghPlayerHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }
    tTempPosition.iPosX++;
    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    //Posição do inimigo
    tTempPosition.hEntityID = ghEnemyHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }
    tTempPosition.iPosX--;
    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}