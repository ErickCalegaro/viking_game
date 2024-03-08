#ifndef __MAIN_H__
#define __MAIN_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/
typedef enum e_Ret_tag {
  RET_OK = 0,
  RET_INV_PARAM,
  RET_INIT_ERROR,
  RET_ABORT,
} e_Ret;

typedef enum e_State_tag {
    STATE_MENU = 0,
    STATE_PAUSE,
    STATE_DEATH,
    STATE_TRAVEL,
    STATE_LEVEL_1,
    STATE_LEVEL_2,
    STATE_LEVEL_3,
    STATE_LEVEL_4,
    STATE_LEVEL_5,
    STATE_GAMEOVER,
    STATE_WIN,
} e_State;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Função principal utilizada pelo windows.
 * \param void
 * \returns Sempre retornará RET_OK 
 */
int main(void);

#endif