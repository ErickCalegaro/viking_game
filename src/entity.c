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
EntityHandle ghPlayerHandle;

// Caracteristicas do inimigo
EntityHandle ghEnemyHandle;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

/**
 * \brief Retorna um novo identificador incremental unico.
 * \param void
 * \returns Retorna um novo ID para ser utilizado em entity_Create; 
 */
static int entity_GetNewID(void);

/**
 * \brief Obtem o index do componente de acordo com o handle informado.
 * \param hHandle Handle(ou ID primario) da entidade, que foi retornado por entity_Create;
 * \returns Caso sucesso, retorna o index fisico do componente em gtComponents; 
 *          Caso o handle seja inválido retorna -1;
 *          Caso não encontre o id com o handle informado retorna -2;
 */
static int entity_GetIndexByHandle(EntityHandle hHandle);

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

static int entity_GetNewID(void)
{
	return giEntities++;
}

static int entity_GetIndexByHandle(EntityHandle hHandle)
{
    if (hHandle < 0){
        printf("Handle invlido informado!\n");
        return -1;
    }
    
    for (int i = 0; i < MAX_COMPONENTS; i++){
        if (gtComponents.atHealthComponents[i].hEntityID == hHandle){
            return i;
        }
    }

    printf("Nao foi possivel encontrar o id do handle informado!\n");
    return -2;
}

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

void entity_Init(void)
{
    memset(&gtComponents, 0x00, sizeof(gtComponents));
	return;
}

EntityHandle entity_Create(void)
{
    int iLocalID = entity_GetNewID();
    // int iLocalIndex = entity_GetFreeIndex(); // !TODO: implementar isto para ser usado no [] 
    if(iLocalID > MAX_COMPONENTS){
        printf("Quantidade maxima de entidades excedido!\n");
        return -1;
    }

    gtComponents.atHealthComponents[iLocalID].hEntityID = iLocalID; //[iLocalID] se tornara um problema
    gtComponents.atPositionComponents[iLocalID].hEntityID = iLocalID;
    gtComponents.iTotalHealthComponents++;
    gtComponents.iTotalPositionComponents++;

    return iLocalID;
}

e_Ret entity_UpdateHealth(t_Health * ptHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(ptHealth->hEntityID);
    if (iEntityIndex < RET_OK){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    gtComponents.atHealthComponents[iEntityIndex].iCurrHealth = ptHealth->iCurrHealth;
    gtComponents.atHealthComponents[iEntityIndex].iMaxHealth  = ptHealth->iMaxHealth;

    return RET_OK;
}

e_Ret entity_UpdatePosition(t_Position * ptPosition)
{
    int iEntityIndex = entity_GetIndexByHandle(ptPosition->hEntityID);
    if (iEntityIndex < RET_OK){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    gtComponents.atPositionComponents[iEntityIndex].iPosX = ptPosition->iPosX;
    gtComponents.atPositionComponents[iEntityIndex].iPosY = ptPosition->iPosY;

    return RET_OK;
}

e_Ret entity_UpdateVelocity(t_Velocity * ptVelocity)
{
    int iTempPos = 0;
    int iEntityIndex = 0;
    
    iEntityIndex = entity_GetIndexByHandle(ptVelocity->hEntityID);
    if (iEntityIndex < RET_OK){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    iTempPos = vector_GetX(ptVelocity->hEntityID);
    if (iTempPos < 0){
        printf("Erro ao resgatar o Vetor X da entidade!\n");
        return RET_POS_ERROR;
    }
    gtComponents.atPositionComponents[iEntityIndex].iPosX = iTempPos + (ptVelocity->iVelocityX * SPEED);

    iTempPos = vector_GetY(ptVelocity->hEntityID);
    if (iTempPos < 0){
        printf("Erro ao resgatar o Vetor Y da entidade!\n");
        return RET_POS_ERROR;
    }
    gtComponents.atPositionComponents[iEntityIndex].iPosY = iTempPos + (ptVelocity->iVelocityY * SPEED);

    return RET_OK;
}

e_Ret entity_CheckHealth(t_Health * ptHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(ptHealth->hEntityID);
    if (iEntityIndex < RET_OK){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    ptHealth->iCurrHealth = gtComponents.atHealthComponents[iEntityIndex].iCurrHealth;
    ptHealth->iMaxHealth = gtComponents.atHealthComponents[iEntityIndex].iMaxHealth;

    return RET_OK;
}

e_Ret entity_CheckPosition(t_Position * ptPosition)
{
    int iEntityIndex = entity_GetIndexByHandle(ptPosition->hEntityID);
    if (iEntityIndex < RET_OK){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    ptPosition->iPosX = gtComponents.atPositionComponents[iEntityIndex].iPosX;
    ptPosition->iPosY = gtComponents.atPositionComponents[iEntityIndex].iPosY;

    // printf("ptPosition->iPosX = [%d]\n", ptPosition->iPosX);
    // printf("ptPosition->iPosY = [%d]\n", ptPosition->iPosY);

    return RET_OK;
}
