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

e_Ret vector_Add(EntityHandle hEntityHandle, int iPosX, int iPosY);

e_Ret vector_Subtract(EntityHandle hEntityHandle, int iPosX, int iPosY);

e_Ret vector_Multiply(EntityHandle hEntityHandle, int iPosX, int iPosY);

e_Ret vector_Divide(EntityHandle hEntityHandle, int iPosX, int iPosY);

int vector_GetX(EntityHandle hEntityHandle);

int vector_GetY(EntityHandle hEntityHandle);

void vector_Print(EntityHandle hEntityHandle);

#endif