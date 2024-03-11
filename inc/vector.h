#ifndef __VECTOR_H__
#define __VECTOR_H__
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
 * \brief Adiciona os valores passados no o componente da entidade referenciada.
 * \param hEntityHandle Handle da entidade que deseja atualizar
 * \param iPosX Quantidade de pixels que deseja adicionar no eixo X
 * \param iPosY Quantidade de pixels que deseja adicionar no eixo Y
 * \returns RET_OK - Caso sucesso; 
 *          RET_POS_ERROR - Caso falhe na obtenção ou atualização da posição da entidade; 
 */
e_Ret vector_Add(EntityHandle hEntityHandle, int iPosX, int iPosY);

/**
 * \brief Subtrai os valores passados no o componente da entidade referenciada.
 * \param hEntityHandle Handle da entidade que deseja atualizar
 * \param iPosX Quantidade de pixels que deseja subtrair no eixo X
 * \param iPosY Quantidade de pixels que deseja subtrair no eixo Y
 * \returns RET_OK - Caso sucesso; 
 *          RET_POS_ERROR - Caso falhe na obtenção ou atualização da posição da entidade; 
 */
e_Ret vector_Subtract(EntityHandle hEntityHandle, int iPosX, int iPosY);

/**
 * \brief Multiplica a posição atual da entidade referenciada.
 * \param hEntityHandle Handle da entidade que deseja atualizar
 * \param iPosX Quantidade de pixels que deseja multiplicar no eixo X
 * \param iPosY Quantidade de pixels que deseja multiplicar no eixo Y
 * \returns RET_OK - Caso sucesso; 
 *          RET_POS_ERROR - Caso falhe na obtenção ou atualização da posição da entidade; 
 */
e_Ret vector_Multiply(EntityHandle hEntityHandle, int iPosX, int iPosY);

/**
 * \brief Divide a posição atual da entidade referenciada.
 * \param hEntityHandle Handle da entidade que deseja atualizar
 * \param iPosX Quantidade de pixels que deseja dividir no eixo X
 * \param iPosY Quantidade de pixels que deseja dividir no eixo Y
 * \returns RET_OK - Caso sucesso; 
 *          RET_POS_ERROR - Caso falhe na obtenção ou atualização da posição da entidade; 
 */
e_Ret vector_Divide(EntityHandle hEntityHandle, int iPosX, int iPosY);

/**
 * \brief Retorna o valor do eixo X da entidade referenciada.
 * \param hEntityHandle Handle da entidade.
 * \returns Caso sucesso, retorna o valor de iPosX da entidade;
 *          Caso falha, retorna -1;
 */
int vector_GetX(EntityHandle hEntityHandle);

/**
 * \brief Retorna o valor do eixo Y da entidade referenciada.
 * \param hEntityHandle Handle da entidade.
 * \returns Caso sucesso, retorna o valor de iPosY da entidade;
 *          Caso falha, retorna -1;
 */
int vector_GetY(EntityHandle hEntityHandle);

/**
 * \brief Imprime os valores de X e Y da entidade referenciada.
 * \param hEntityHandle Handle da entidade.
 * \returns void
 */
void vector_Print(EntityHandle hEntityHandle);

#endif