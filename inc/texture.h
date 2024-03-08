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

#endif