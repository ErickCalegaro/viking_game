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

e_Ret map_Create(e_State eState);

e_Ret map_Draw(void);

e_Ret map_Load(int iArrayMap[NUM_ROWS][NUM_COLUMNS]);

#endif