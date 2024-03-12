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
static SDL_Texture    *gptTextureDirt;
static SDL_Texture    *gptTextureGrass;
static int             gaCurrMap[NUM_ROWS][NUM_COLUMNS];


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
            gptTextureDirt  = texture_Load(TILE_DIRT_L1);
            gptTextureGrass = texture_Load(TILE_GRASS_L1);
            break;
        case STATE_LEVEL_2:
            gptTextureDirt  = texture_Load(TILE_DIRT_L2);
            gptTextureGrass = texture_Load(TILE_GRASS_L2);
            break;
        case STATE_LEVEL_3:
            gptTextureDirt  = texture_Load(TILE_DIRT_L3);
            gptTextureGrass = texture_Load(TILE_GRASS_L3);
            break;
        case STATE_LEVEL_4:
            gptTextureDirt  = texture_Load(TILE_DIRT_L4);
            gptTextureGrass = texture_Load(TILE_GRASS_L4);
            break;
        case STATE_LEVEL_5:
            gptTextureDirt  = texture_Load(TILE_DIRT_L5);
            gptTextureGrass = texture_Load(TILE_GRASS_L5);
            break;
        default:
            printf("Nao existem texturas para o estado [%d]!\n", eState);
            return RET_INV_PARAM;
    }

    if (gptTextureDirt == NULL || gptTextureGrass == NULL){
        printf("Não foi possivel criar as texturas de blocos!\n");
        return RET_SDL_ERROR;
    }

    gtSourceRect.x = gtSourceRect.y = 0;
    gtDestRect.x   = gtDestRect.y   = 0;
    gtSourceRect.h = gtDestRect.h   = TILE_SCALE;
    gtSourceRect.w = gtDestRect.w   = TILE_SCALE;

    return RET_OK;
}

e_Ret map_Load(int aNewMap[NUM_ROWS][NUM_COLUMNS])
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

    for (int iRow = 0; iRow < NUM_ROWS; iRow++)
    {
        for (int iColumn = 0; iColumn < NUM_COLUMNS; iColumn++)
        {
            eTileType = gaCurrMap[iRow][iColumn];

            gtDestRect.x = iColumn * TILE_SCALE;
            gtDestRect.y = iRow * TILE_SCALE;

            switch (eTileType)
            {
                case TILE_AIR: //Do Nothing!
                    break;
                case TILE_DIRT:
                    eRet = texture_Draw(gptTextureDirt, gtSourceRect, gtDestRect);
                    break;
                case TILE_GRASS:
                    eRet = texture_Draw(gptTextureGrass, gtSourceRect, gtDestRect);
                    break;
                default:
                    break;
            }

            if (eRet){
                printf("Falha ao desenhar o bloco[%d][%d] do tipo [%d]!\n", iColumn, iRow, eTileType);
                return RET_SDL_ERROR;
            }
        }
    }

    return RET_OK;
}