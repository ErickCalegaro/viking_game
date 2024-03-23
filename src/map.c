/**
 * \file    map.c
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

static SDL_Rect        gtSourceRect;
static SDL_Rect        gtDestRect;
static SDL_Texture    *gptTexture;
static e_TileType      gaCurrMap[NUM_ROWS][NUM_COLUMNS];


/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/


/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret map_Create(e_State eState)
{
    switch (eState)
    {
        case STATE_LEVEL_1:
            gptTexture  = texture_Load(TILE_MAP_L1);
            break;
        case STATE_LEVEL_2:
            gptTexture  = texture_Load(TILE_MAP_L2);
            break;
        case STATE_LEVEL_3:
            gptTexture  = texture_Load(TILE_MAP_L3);
            break;
        case STATE_LEVEL_4:
            gptTexture  = texture_Load(TILE_MAP_L4);
            break;
        case STATE_LEVEL_5:
            gptTexture  = texture_Load(TILE_MAP_L5);
            break;
        default:
            printf("Nao existem texturas para o estado [%d]!\n", eState);
            return RET_INV_PARAM;
    }

    if (gptTexture == NULL){
        printf("Não foi possivel criar as texturas de blocos!\n");
        return RET_SDL_ERROR;
    }

    gtSourceRect.x = gtSourceRect.y = 0;
    gtDestRect.x   = gtDestRect.y   = 0;
    gtSourceRect.h = gtDestRect.h   = TILE_SCALE;
    gtSourceRect.w = gtDestRect.w   = TILE_SCALE;

    return RET_OK;
}

e_Ret map_Load(e_TileType aNewMap[NUM_ROWS][NUM_COLUMNS])
{
    for (int iRow = 0; iRow < NUM_ROWS; iRow++){
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++){
            gaCurrMap[iRow][iColumn] = aNewMap[iRow][iColumn];
        }
    }
    
    return RET_OK;
}

e_Ret map_Draw(void)
{
    e_TileType eTileType = 0;
    e_Ret eRet = RET_OK;
    gtSourceRect.w = TILE_SCALE / 2;
    gtSourceRect.h = TILE_SCALE / 2;

    gtDestRect.w   = TILE_SCALE;
    gtDestRect.h   = TILE_SCALE;

    for (int iRow = 0; iRow < NUM_ROWS; iRow++)
    {
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++)
        {
            eTileType = gaCurrMap[iRow][iColumn];

            gtDestRect.x = iColumn * TILE_SCALE;
            gtDestRect.y = iRow * TILE_SCALE;
            gtSourceRect.x = (eTileType == 0) ? 0 : (eTileType % 8) * (TILE_SCALE / 2);
            gtSourceRect.y = (eTileType == 0) ? 0 : (eTileType / 8) * (TILE_SCALE / 2);

            // printf("=====================\n");
            // printf("eTileType      = [%d]\n", eTileType);
            // printf("eTileType %% 8  = [%d]\n", (eTileType % 8));
            // printf("eTileType / 8  = [%d]\n", (eTileType / 8));
            // printf("gtSourceRect.x = [%d]\n", gtSourceRect.x);
            // printf("gtSourceRect.y = [%d]\n", gtSourceRect.y);

            eRet = texture_Draw(gptTexture, gtSourceRect, gtDestRect);
            
            if (eRet){
                printf("Falha ao desenhar o bloco[%d][%d] do tipo [%d]!\n", iColumn, iRow, eTileType);
                return RET_SDL_ERROR;
            }
        }
    }

    return RET_OK;
}