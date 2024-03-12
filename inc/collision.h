#ifndef __COLISION_H__
#define __COLISION_H__
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

void collision_Load(int aNewCollision[NUM_ROWS][NUM_COLUMNS]);

bool collision_Check(EntityHandle hEntityHandle);

bool collision_CheckVector(t_Position * tPositionEntity);

#endif