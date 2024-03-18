#ifndef __SCREEN_H__
#define __SCREEN_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_test_font.h>
#include <SDL2/SDL_ttf.h>

#include "texture.h"
#include "object.h"
#include "map.h"
#include "collision.h"
#include "sprite.h"

#include "level_1.h"

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define FPS             60
#define FRAME_DELAY     1000 / FPS

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   640

#define TEXTURE_PLAYER  "player.png"
#define TEXTURE_WOLF    "wolf.png"
#define TEXTURE_TROLL   "troll.png"
#define TEXTURE_WARRIOR "warrior.png"

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

extern SDL_Renderer *gptRenderer;
extern t_GameObject gtPlayerObject;
extern t_GameObject gtEnemyObject;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Instancia a biblioteca grafica e seus modulos.
 *        Deve ser chamada obrigatoriamente no inicio do codigo.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_INIT_ERROR - Caso falhe; 
 */
e_Ret screen_InitSDL(void);

/**
 * \brief Cria a janela base para execução do jogo.
 *        Deve ser chamada obrigatoriamente após screen_InitSDL.
 * \param bFullscreen Indica se o canva será representado na tela toda
 * \returns RET_OK - Caso sucesso; 
 *          RET_INIT_ERROR - Caso falhe; 
 */
e_Ret screen_CreateWindow(bool bFullscreen);

/**
 * \brief Atualiza os componentes da tela.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_POS_ERROR - Caso falhe na obtenção da posição da entidade; 
 *          RET_OBJ_ERROR - Caso falhe na atualização do objeto na tela;
 */
e_Ret screen_Update(void);

/**
 * \brief Renderiza a tela.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
e_Ret screen_Render(void);

/**
 * \brief Libera os recursos alocados por screen_InitSDL e encerra a biblioteca.
 * \param void
 * \returns Sempre retornará RET_OK 
 */
e_Ret screen_DestroySDL(void);

#endif