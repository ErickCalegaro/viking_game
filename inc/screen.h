#ifndef __SCREEN_H__
#define __SCREEN_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_font.h>
#include <SDL2/SDL_ttf.h>

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Cria a janela base para execução do jogo.
 *        Deve ser chamada obrigatoriamente no inicio do codigo.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_INIT_ERROR - Caso falhe; 
 */
e_Ret screen_CreateWindow(void);

#endif