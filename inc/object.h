#ifndef __OBJECT_H__
#define __OBJECT_H__
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

typedef struct {
    int iPosX;
    int iPosY;
    SDL_Rect        tSourceRect;
    SDL_Rect        tDestRect;
    SDL_Texture    *ptTexture;
} t_GameObject;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Cria um objeto grafico com o path do arquivo e posição inicial.
 * \param ptGameObject Referencia para struct do tipo t_GameObject que receberá o objeto
 * \param TextureSheet Path do arquivo de imagem com a extensão
 * \param iPosX Posição X inicial
 * \param iPosY Posição Y inicial
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
e_Ret object_Create(t_GameObject * ptGameObject, const char *TextureSheet, int iPosX, int iPosY);

/**
 * \brief Atualiza o objeto de acordo com a referencia de sua estrutura.
 * \param ptGameObject Referencia para struct do objeto que será atualizado.
 * \param tPosition Referencia para struct com as informações de localização do objeto.
 * \returns Retorna sempre RET_OK; 
 */
e_Ret object_Update(t_GameObject * ptGameObject, t_Position * tPosition);

/**
 * \brief Renderiza o objeto de acordo com a referencia de sua estrutura.
 * \param ptGameObject Referencia para struct do objeto que será renderizado.
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
e_Ret object_Render(t_GameObject * ptGameObject);

#endif