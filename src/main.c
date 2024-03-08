/**
 * \file    main.c
 * \version 0.0.1
 * \date    07/03/2024
 * \author  Erick Calegaro
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "main.h"
#include "screen.h"

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/
static e_State geState = STATE_MENU;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

/**
 * \brief Inicializa todos os recursos necessário para execução do jogo.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_INIT_ERROR - Caso falhe;  
 */
static e_Ret main_Init(void);

/**
 * \brief Nucleo principal de gerenciamento de estado, 
 *        controla a ordem de exibição de todas as telas do jogo.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_???_ERROR - Caso falhe;  
 */
static e_Ret main_Loop(void);

/**
 * \brief Setter de estado global
 * \param eState Estado que deseja definir o jogo
 * \returns void
 */
static void main_SetState(e_State eState);

/**
 * \brief Getter de estado global
 * \param void
 * \returns Retorna o estado atual do jogo no tipo e_State
 */
static e_State main_GetState(void);

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/
static e_Ret main_Init(void)
{
    e_Ret eRet = RET_OK;
    eRet = screen_CreateWindow();
    return eRet;
}

static e_Ret main_Loop(void)
{
    e_Ret   eRet        = RET_OK;
    e_State eNextState  = geState;

    do{
        switch (main_GetState())
        {
            case STATE_MENU:        // Menu inicial do jogo                
                break;
            case STATE_PAUSE:       // Menu de pausa do jogo
                break;
            case STATE_DEATH:       // Tela de morte do jogador (Conta vidas)
                break;
            case STATE_TRAVEL:      // Cutscene de viagem
                break;
            case STATE_LEVEL_1:     // Nivel 1 - Floresta Viking
                break;
            case STATE_LEVEL_2:     // Nivel 2 - Montanhas Geladas
                break;
            case STATE_LEVEL_3:     // Nivel 3 - Vilarejo Viking
                break;
            case STATE_LEVEL_4:     // Nivel 4 - Caverna do Dragão
                break;
            case STATE_LEVEL_5:     // Nivel 5 - Fortaleza Viking
                break;
            case STATE_GAMEOVER:    // Tela de fim de jogo - Derrota
                break;
            case STATE_WIN:         // Tela de fim de jogo - Vitoria
                break;
            default:                // Erro fatal
                break;
        }

        if (eRet == RET_OK){
            main_SetState(eNextState);
        }
        
    } while (TRUE);

    return RET_OK;
}

static void main_SetState(e_State eState)
{
    geState = eState;
}

static e_State main_GetState(void)
{
    return geState;
}

/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/
int main(void)
{
    main_Init();
    main_Loop();
    return RET_OK;
}
