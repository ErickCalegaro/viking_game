/**
 * \file    collision.c
 * \version 0.0.1
 * \date    12/03/2024
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

static e_TileType gaCollisionMap[NUM_ROWS][NUM_COLUMNS];

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/


/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

void collision_Load(e_TileType aNewCollision[NUM_ROWS][NUM_COLUMNS])
{
    for (int iRow = 0; iRow < NUM_ROWS; iRow++){
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++){
            gaCollisionMap[iRow][iColumn] = aNewCollision[iRow][iColumn];
        }
    }
    
    return;
}

bool collision_Check(EntityHandle hEntityHandle)
{
    t_Position  tPositionEntity;
    t_Position  tPositionTile;
    t_Scale     tScaleEntity;
    e_TileType  eTileType;

    tPositionEntity.hEntityID = hEntityHandle;
    if (entity_CheckPosition(&tPositionEntity)){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return false;
    }

    tScaleEntity.hEntityID = hEntityHandle;
    if (entity_CheckScale(&tScaleEntity)){
        printf("Nao foi possivel obter a escala da entidade!\n");
        return false;
    }

    for (int iRow = 0; iRow < NUM_ROWS; iRow++)
    {
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++)
        {
            eTileType = gaCollisionMap[iRow][iColumn];

            tPositionTile.iPosX = iColumn * TILE_SCALE;
            tPositionTile.iPosY = iRow * TILE_SCALE;

            if (eTileType != TILE_AIR){
                if (tPositionEntity.iPosX + tScaleEntity.iWidth  >= tPositionTile.iPosX    &&
                    tPositionTile.iPosX   + TILE_SCALE           >= tPositionEntity.iPosX  &&
                    tPositionEntity.iPosY + tScaleEntity.iHeight >= tPositionTile.iPosY    &&
                    tPositionTile.iPosY   + TILE_SCALE           >= tPositionEntity.iPosY  ){
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool collision_CheckVector(t_Position * tPositionEntity)
{
    t_Position  tPositionTile;
    t_Collision tCollisionBlock;
    e_TileType  eTileType;

    tCollisionBlock.hEntityID = tPositionEntity->hEntityID;
    if (entity_CheckCollision(&tCollisionBlock)){
        printf("Nao foi possivel obter a escala da entidade!\n");
        return false;
    }

    for (int iRow = 0; iRow < NUM_ROWS; iRow++)
    {
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++)
        {
            eTileType = gaCollisionMap[iRow][iColumn];

            tPositionTile.iPosX = iColumn * TILE_SCALE;
            tPositionTile.iPosY = iRow * TILE_SCALE;

            if (eTileType != TILE_AIR){
                if ((tPositionEntity->iPosX + tCollisionBlock.iPosX + tCollisionBlock.iWidth)  >= // Direita p/ Esquerda
                        (tPositionTile.iPosX)                                                  && 
                    (tPositionTile.iPosX    + TILE_SCALE)                                      >= // Esquerda p/ Direita
                        (tPositionEntity->iPosX + tCollisionBlock.iPosX)                       &&  
                    (tPositionEntity->iPosY + tCollisionBlock.iPosY + tCollisionBlock.iHeight) >= // Cima p/ Baixo
                        (tPositionTile.iPosY)                                                  && 
                    (tPositionTile.iPosY    + TILE_SCALE)                                      >= // Baixo p/ Cima
                        (tPositionEntity->iPosY + tCollisionBlock.iPosY)                       ){ 
                    return true;
                }
            }
        }
    }
    
    return false;
}
