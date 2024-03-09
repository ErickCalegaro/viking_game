#ifndef __MAP_H__
#define __MAP_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/


/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define NUM_ROWS    20
#define NUM_COLUMNS 25

#define TILE_DIRT_L1    "level1/dirt.png"
#define TILE_GRASS_L1   "level1/grass.png"
#define TILE_DIRT_L2    "level2/dirt.png"
#define TILE_GRASS_L2   "level2/grass.png"
#define TILE_DIRT_L3    "level3/dirt.png"
#define TILE_GRASS_L3   "level3/grass.png"
#define TILE_DIRT_L4    "level4/dirt.png"
#define TILE_GRASS_L4   "level4/grass.png"
#define TILE_DIRT_L5    "level5/dirt.png"
#define TILE_GRASS_L5   "level5/grass.png"


/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

typedef enum e_TileType_tag {
    TILE_AIR = 0,
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
 * \param iArrayMap Matriz de inteiros do tipo e_TileType.
 * \returns Retorna sempre RET_OK; 
 */
e_Ret map_Load(int iArrayMap[NUM_ROWS][NUM_COLUMNS]);

/**
 * \brief Desenha na tela o level design definido em map_Load.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe ao desenhar algum bloco;
 */
e_Ret map_Draw(void);


#endif