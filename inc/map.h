#ifndef __MAP_H__
#define __MAP_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/


/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define NUM_ROWS        20
#define NUM_COLUMNS     40
#define TILE_SCALE      32

#define TILE_MAP_L1    "level1/tileset.png"
#define TILE_MAP_L2    "level2/tileset.png"
#define TILE_MAP_L3    "level3/tileset.png"
#define TILE_MAP_L4    "level4/tileset.png"
#define TILE_MAP_L5    "level5/tileset.png"

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

typedef enum e_TileType_tag {
    TILE_AIR = 12,
    TILE_DIRT,
    TILE_GRASS,
} e_TileType;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Carrega as texturas para os blocos de acordo com a fase.
 * \param eState Identifica qual a fase atual do jogo.
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe no carregamento da textura;
 *          RET_INV_PARAM - Caso receba uma fase inválida;
 */
e_Ret map_Create(e_State eState);

/**
 * \brief Copia para a memoria o molde de level design passado no parametro.
 * \param aNewMap Matriz de inteiros do tipo e_TileType.
 * \returns Retorna sempre RET_OK; 
 */
e_Ret map_Load(e_TileType aNewMap[NUM_ROWS][NUM_COLUMNS]);

/**
 * \brief Desenha na tela o level design definido em map_Load.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe ao desenhar algum bloco;
 */
e_Ret map_Draw(void);


#endif