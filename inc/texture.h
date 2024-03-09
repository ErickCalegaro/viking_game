#ifndef __TEXTURE_H__
#define __TEXTURE_H__
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
 * \brief Cria texturas genericas com base em arquivos de imagem.
 * \param psTexturePath Path do arquivo de imagem com a extensão
 * \returns Caso sucesso retorna um ponteiro do tipo SDL_Texture; 
 *          Caso falhe em alguma etapa retornará NULL; 
 */
SDL_Texture * texture_Load(const char * psTexturePath);

/**
 * \brief Renderiza o objeto de acordo com a sua textura e posição.
 * \param ptTexture Textura do objeto que será renderizado.
 * \param tSourceRect Posição e tamanho do objeto no arquivo de origem.
 * \param tDestRect Posição e tamanho do objeto no renderer.
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
e_Ret texture_Draw(SDL_Texture *ptTexture, SDL_Rect tSourceRect, SDL_Rect tDestRect);

#endif