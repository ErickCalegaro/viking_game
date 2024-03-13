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
 *          Caso o handle seja inválido ou não encontre o id retorna RET_NEGATIVE;
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
        return RET_NEGATIVE;
    }
    
    for (int i = 0; i < MAX_COMPONENTS; i++){
        if (gtComponents.atPositionComponents[i].hEntityID == hHandle){ // !TODO: Levar em consideração outros componentes
            return i;
        }
    }

    printf("Nao foi possivel encontrar o id do handle informado!\n");
    return RET_NEGATIVE;
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
        return RET_NEGATIVE;
    }

    gtComponents.atHealthComponents[iLocalID].hEntityID = iLocalID; //[iLocalID] se tornara um problema
    gtComponents.atPositionComponents[iLocalID].hEntityID = iLocalID;
    gtComponents.atScaleComponents[iLocalID].hEntityID = iLocalID;
    gtComponents.iTotalHealthComponents++;
    gtComponents.iTotalPositionComponents++;
    gtComponents.iTotalScaleComponents++;

    return iLocalID;
}

e_Ret entity_UpdateHealth(t_Health * ptHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(ptHealth->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
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
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    gtComponents.atPositionComponents[iEntityIndex].iPosX = ptPosition->iPosX;
    gtComponents.atPositionComponents[iEntityIndex].iPosY = ptPosition->iPosY;

    return RET_OK;
}

e_Ret entity_UpdateVelocity(t_Velocity * ptVelocity)
{
    int iEntityIndex = 0;

    t_Position tNewPosition;
    tNewPosition.hEntityID = ptVelocity->hEntityID;
    
    iEntityIndex = entity_GetIndexByHandle(ptVelocity->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    tNewPosition.iPosX = vector_GetX(ptVelocity->hEntityID);
    if (tNewPosition.iPosX == RET_NEGATIVE){
        printf("Erro ao resgatar o Vetor X da entidade!\n");
        return RET_POS_ERROR;
    }

    tNewPosition.iPosY = vector_GetY(ptVelocity->hEntityID);
    if (tNewPosition.iPosY == RET_NEGATIVE){
        printf("Erro ao resgatar o Vetor Y da entidade!\n");
        return RET_POS_ERROR;
    }

    tNewPosition.iPosX += (ptVelocity->iVelocityX * SPEED);
    tNewPosition.iPosY += (ptVelocity->iVelocityY * SPEED);

    // Verifica a colisão antes que ela aconteça
    if (collision_CheckVector(&tNewPosition)){  
        // printf("Colisao identificada!\n");
        return RET_COLLISION;
    }

    gtComponents.atPositionComponents[iEntityIndex].iPosX = tNewPosition.iPosX;
    gtComponents.atPositionComponents[iEntityIndex].iPosY = tNewPosition.iPosY;

    return RET_OK;
}

e_Ret entity_UpdateScale(t_Scale * ptScale)
{
    int iEntityIndex = entity_GetIndexByHandle(ptScale->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    gtComponents.atScaleComponents[iEntityIndex].iHeight = ptScale->iHeight;
    gtComponents.atScaleComponents[iEntityIndex].iWidth = ptScale->iWidth;

    return RET_OK;
}

e_Ret entity_UpdateCollision(t_Collision * ptCollision)
{
    int iEntityIndex = entity_GetIndexByHandle(ptCollision->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    gtComponents.atCollisionComponents[iEntityIndex].iPosX   = ptCollision->iPosX;
    gtComponents.atCollisionComponents[iEntityIndex].iPosY   = ptCollision->iPosY;
    gtComponents.atCollisionComponents[iEntityIndex].iHeight = ptCollision->iHeight;
    gtComponents.atCollisionComponents[iEntityIndex].iWidth  = ptCollision->iWidth;

    return RET_OK;
}


e_Ret entity_CheckHealth(t_Health * ptHealth)
{
    int iEntityIndex = entity_GetIndexByHandle(ptHealth->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
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
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    ptPosition->iPosX = gtComponents.atPositionComponents[iEntityIndex].iPosX;
    ptPosition->iPosY = gtComponents.atPositionComponents[iEntityIndex].iPosY;

    // printf("ptPosition->iPosX = [%d]\n", ptPosition->iPosX);
    // printf("ptPosition->iPosY = [%d]\n", ptPosition->iPosY);

    return RET_OK;
}

e_Ret entity_CheckScale(t_Scale * ptScale)
{
    int iEntityIndex = entity_GetIndexByHandle(ptScale->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    ptScale->iHeight = gtComponents.atScaleComponents[iEntityIndex].iHeight;
    ptScale->iWidth = gtComponents.atScaleComponents[iEntityIndex].iWidth;

    return RET_OK;
}

e_Ret entity_CheckCollision(t_Collision * ptCollision)
{
    int iEntityIndex = entity_GetIndexByHandle(ptCollision->hEntityID);
    if (iEntityIndex == RET_NEGATIVE){
        printf("Index invalido!\n");
        return RET_INV_PARAM;
    }

    ptCollision->iPosX   = gtComponents.atCollisionComponents[iEntityIndex].iPosX;
    ptCollision->iPosY   = gtComponents.atCollisionComponents[iEntityIndex].iPosY;
    ptCollision->iHeight = gtComponents.atCollisionComponents[iEntityIndex].iHeight;
    ptCollision->iWidth  = gtComponents.atCollisionComponents[iEntityIndex].iWidth;
    
    return RET_OK;
}
