/**
 * \file    level_1.c
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

static e_TileType giArrayMapLevel1[20][25] = {
    {0, 0, 0, 0, 0, 0, 0, T, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, T, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, G, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, T, T, T, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, T, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, T, T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {T, T, T, T, T, T, T, T, G, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

/**
 * \brief Cria e inicializa o mapa que será utilizado na fase 1.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_MAP_ERROR - Caso falhe na criação do mapa;  
 */
static e_Ret level_1_Init(void);

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

static e_Ret level_1_Init(void)
{
    e_Ret eRet = RET_OK;
    eRet = map_Create(STATE_LEVEL_1);
    if (eRet){
        printf("Nao foi possivel inicializar as texturas!\n");
        return RET_MAP_ERROR;
    }

    map_Load(giArrayMapLevel1);
    collision_Load(giArrayMapLevel1);

    return RET_OK;
}


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret level_1_Loop(e_State * peNextState)
{
    peNextState = peNextState; //Unref parameter
    
    e_Ret   eRet         = RET_OK;
    Uint32  uiFrameStart = 0;
    int     iFrameTime   = 0;

    eRet = level_1_Init();
    if (eRet){
        printf("Nao foi possivel inicializar o mapa!\n");
        return RET_INIT_ERROR;
    }

    do{
        uiFrameStart = SDL_GetTicks();

        control_HandleEvents();
        
        eRet = keyboard_HandleEvents();
        if (eRet){
            printf("Nao foi possivel movimentar o jogador!\n");
            break;
        }

        screen_Update();
        eRet = screen_Render();
        if (eRet){
            printf("Nao foi possivel renderizar a tela!\n");
            break;
        }
        
        iFrameTime = SDL_GetTicks() - uiFrameStart;

        if (FRAME_DELAY > iFrameTime){ //Trava de FPS
            SDL_Delay(FRAME_DELAY - iFrameTime);
        }
        
    } while (control_GetRunning());

    return RET_OK;
}