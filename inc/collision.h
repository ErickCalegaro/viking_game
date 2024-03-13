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

/**
 * \brief Copia para a memoria o molde de level design passado no parametro.
 * \param aNewMap Matriz de inteiros do tipo e_TileType.
 * \returns Retorna sempre RET_OK; 
 */
void collision_Load(e_TileType aNewCollision[NUM_ROWS][NUM_COLUMNS]);

/**
 * \brief Verifica se houve colisão com o level design de acordo com a posição atual da entidade.
 * \param hEntityHandle Handle da entidade que deseja verificar a colisão
 * \returns true caso ocorra a colisão; false caso não seja identificada colisão; 
 */
bool collision_Check(EntityHandle hEntityHandle);

/**
 * \brief Verifica se haverá colisão com o level design de acordo com os dados de posição parametrizados.
 * \param ptPosition Struct com as informações do handle e posição para validação.
 * \returns true caso seja identificada colisão; false caso não seja identificada colisão; 
 */
bool collision_CheckVector(t_Position * tPositionEntity);

#endif