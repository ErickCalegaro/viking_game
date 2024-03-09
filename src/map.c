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
static int             giArrayMap[NUM_ROWS][NUM_COLUMNS];


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
            return RET_MAP_ERROR;
    }

    if (gptTextureDirt == NULL || gptTextureGrass == NULL){
        printf("Não foi possivel criar as texturas de blocos!\n");
        return RET_SDL_ERROR;
    }

    gtSourceRect.x = gtSourceRect.y = 0;
    gtDestRect.x   = gtDestRect.y   = 0;
    gtSourceRect.h = gtDestRect.h   = 32;
    gtSourceRect.w = gtDestRect.w   = 32;

    return RET_OK;
}

e_Ret map_Draw(void)
{
    e_TileType eTileType = 0;
    e_Ret eRet = RET_OK;

    for (size_t row = 0; row < NUM_ROWS; row++)
    {
        for (size_t column = 0; column < NUM_COLUMNS; column++)
        {
            eTileType = giArrayMap[row][column];

            gtDestRect.x = column * 32;
            gtDestRect.y = row * 32;

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
                printf("Falha ao desenhar o bloco[%d][%d] do tipo [%d]!\n", column, row, eTileType);
                return RET_SDL_ERROR;
            }
        }
    }

    return RET_OK;
}

e_Ret map_Load(int iArrayMap[NUM_ROWS][NUM_COLUMNS])
{
    for (size_t row = 0; row < NUM_ROWS; row++){
        for (size_t column = 0; column < NUM_COLUMNS; column++){
            giArrayMap[row][column] = iArrayMap[row][column];
        }
    }
    
    return RET_OK;
}
