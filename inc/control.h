#ifndef __CONTROL_H__
#define __CONTROL_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "entity.h"

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
 * \brief Setter de execução do jogo
 * \param bIsRunning Estado que deseja definir a execução
 * \returns void
 */
void control_SetRunning(bool bIsRunning);

/**
 * \brief Getter de execução do jogo
 * \param void
 * \returns Retorna o estado atual de execução
 */
bool control_GetRunning(void);

/**
 * \brief Gerenciador de eventos do SO.
 *      Alterar estes retornos para enum de eventos
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_ABORT - Caso janela seja fechada;  
 */
e_Ret control_HandleEvents(void); 

//Test Only
e_Ret control_TestMove(void);

#endif