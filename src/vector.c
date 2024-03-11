/**
 * \file    vector.c
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

e_Ret vector_Add(EntityHandle hEntityHandle, int iPosX, int iPosY)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;

    tTempPosition.hEntityID = hEntityHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    tTempPosition.iPosX += iPosX;
    tTempPosition.iPosY += iPosY;

    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}

e_Ret vector_Subtract(EntityHandle hEntityHandle, int iPosX, int iPosY)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;

    tTempPosition.hEntityID = hEntityHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    tTempPosition.iPosX -= iPosX;
    tTempPosition.iPosY -= iPosY;

    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}

e_Ret vector_Multiply(EntityHandle hEntityHandle, int iPosX, int iPosY)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;
    float fTempVar = 0.00;

    tTempPosition.hEntityID = hEntityHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    if (iPosX != 0){
        fTempVar = (float)tTempPosition.iPosX * (float)iPosX;
        tTempPosition.iPosX = (int)fTempVar;
    }

    if (iPosY != 0){
        fTempVar = (float)tTempPosition.iPosY * (float)iPosY;
        tTempPosition.iPosY = (int)fTempVar;
    }

    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}

e_Ret vector_Divide(EntityHandle hEntityHandle, int iPosX, int iPosY)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;
    float fTempVar = 0.00;

    tTempPosition.hEntityID = hEntityHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }

    if (iPosX != 0){
        fTempVar = (float)tTempPosition.iPosX * (float)iPosX;
        tTempPosition.iPosX = (int)fTempVar;
    }

    if (iPosY != 0){
        fTempVar = (float)tTempPosition.iPosY * (float)iPosY;
        tTempPosition.iPosY = (int)fTempVar;
    }

    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir novas posicoes para entidade!\n");
        return RET_POS_ERROR;
    }

    return RET_OK;
}

int vector_GetX(EntityHandle hEntityHandle)
{
    {
    t_Position tTempPosition;

    tTempPosition.hEntityID = hEntityHandle;
    if (entity_CheckPosition(&tTempPosition)){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return -1;
    }

    return tTempPosition.iPosX;
}
}

int vector_GetY(EntityHandle hEntityHandle)
{
    t_Position tTempPosition;

    tTempPosition.hEntityID = hEntityHandle;
    if (entity_CheckPosition(&tTempPosition)){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return -1;
    }

    return tTempPosition.iPosY;
}

void vector_Print(EntityHandle hEntityHandle)
{
    t_Position tTempPosition;

    tTempPosition.hEntityID = hEntityHandle;
    if (entity_CheckPosition(&tTempPosition)){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return;
    }

    printf("(%d,%d)", tTempPosition.iPosX, tTempPosition.iPosY);
    return;
}