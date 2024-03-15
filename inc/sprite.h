#ifndef __SPRITE_H__
#define __SPRITE_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/


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
 * \brief Entry Point para renderização de objetos moveis animados e estaticos.
 * \param ptGameObject Referencia para ptGameObject, que contem os dados sobre a textura e animação.
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
e_Ret sprite_Render(t_GameObject * ptGameObject);

#endif