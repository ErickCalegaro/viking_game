/**
 * \file    entity.c
 * \version 0.0.1
 * \date    09/03/2024
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
static int giEntities = 0;
static t_ComponentLists gtComponents;

// Caracteristicas do personagem
EntityHandle hPlayerHandle;

// Caracteristicas do inimigo
EntityHandle hEnemyHandle;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

static int entity_GetNewID(void);

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

static int entity_GetNewID(void)
{
	return giEntities++;
}

static int entity_GetIndexByHandle(EntityHandle hHandle)
{
    if (hHandle < 0)
        return -1;
    
    for (int i = 0; i < MAX_COMPONENTS; i++){
        if (gtComponents.tHealthComponents[i].iEntityID == hHandle){
            return i;
        }
    }

    return -2;
}

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

EntityHandle entity_Create(void)
{
    int iLocalID = entity_GetNewID();
    // int iLocalIndex = entity_GetFreeIndex(); // !TODO: implementar isto para ser usado no [] 
    if(iLocalID > MAX_COMPONENTS){
        return -1;
    }

    gtComponents.tHealthComponents[iLocalID].iEntityID = iLocalID; //[iLocalID] se tornara um problema
    gtComponents.tPositionComponents[iLocalID].iEntityID = iLocalID;
    gtComponents.iTotalHealthComponents++;
    gtComponents.iTotalPositionComponents++;

    return iLocalID;
}

e_Ret entity_UpdateHealth(t_Health * tHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(tHealth->iEntityID);
    if (iEntityIndex < RET_OK){
        return RET_INV_PARAM;
    }

    gtComponents.tHealthComponents[iEntityIndex].iCurrHealth = tHealth->iCurrHealth;
    gtComponents.tHealthComponents[iEntityIndex].iMaxHealth  = tHealth->iMaxHealth;

    return RET_OK;
}

e_Ret entity_UpdatePosition(t_Position * tPosition)
{
    int iEntityIndex = entity_GetIndexByHandle(tPosition->iEntityID);
    if (iEntityIndex < RET_OK){
        return RET_INV_PARAM;
    }

    gtComponents.tPositionComponents[iEntityIndex].iPosX = tPosition->iPosX;
    gtComponents.tPositionComponents[iEntityIndex].iPosY = tPosition->iPosY;

    return RET_OK;
}

e_Ret entity_CheckHealth(t_Health * tHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(tHealth->iEntityID);
    if (iEntityIndex < RET_OK){
        return RET_INV_PARAM;
    }

    tHealth->iCurrHealth = gtComponents.tHealthComponents[iEntityIndex].iCurrHealth;
    tHealth->iMaxHealth = gtComponents.tHealthComponents[iEntityIndex].iMaxHealth;

    return RET_OK;
}

e_Ret entity_CheckPosition(t_Position * tPosition)
{
    int iEntityIndex = entity_GetIndexByHandle(tPosition->iEntityID);
    if (iEntityIndex < RET_OK){
        return RET_INV_PARAM;
    }

    tPosition->iPosX = gtComponents.tPositionComponents[iEntityIndex].iPosX;
    tPosition->iPosY = gtComponents.tPositionComponents[iEntityIndex].iPosY;

    return RET_OK;
}