#ifndef __ENTITY_H__
#define __ENTITY_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/


/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define MAX_COMPONENTS 100

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/
typedef int EntityHandle;

typedef struct {
    int iEntityID;
    int iPosX;
    int iPosY;
} t_Position;

typedef struct {
    int iEntityID;
    int iCurrHealth;
    int iMaxHealth;
} t_Health;

typedef struct {
    t_Health tHealthComponents[MAX_COMPONENTS];
    t_Position tPositionComponents[MAX_COMPONENTS];
    int iTotalHealthComponents;
    int iTotalPositionComponents;
} t_ComponentLists;

extern EntityHandle hPlayerHandle;
extern EntityHandle hEnemyHandle;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

EntityHandle entity_Create(void);
e_Ret entity_UpdateHealth(t_Health * tHealth);
e_Ret entity_UpdatePosition(t_Position * tPosition);
e_Ret entity_CheckHealth(t_Health * tHealth);
e_Ret entity_CheckPosition(t_Position * tPosition);

#endif