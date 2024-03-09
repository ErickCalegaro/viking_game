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
    EntityHandle    iEntityID;
    int             iPosX;
    int             iPosY;
} t_Position;

typedef struct {
    EntityHandle    iEntityID;
    int             iCurrHealth;
    int             iMaxHealth;
} t_Health;

typedef struct {
    t_Health    tHealthComponents   [MAX_COMPONENTS];
    t_Position  tPositionComponents [MAX_COMPONENTS];
    int         iTotalHealthComponents;
    int         iTotalPositionComponents;
} t_ComponentLists;

extern EntityHandle hPlayerHandle;
extern EntityHandle hEnemyHandle;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Inicializa uma nova entidade na estrutura global gtComponents
 * \param void
 * \returns Caso sucesso, retorna o Handle(ou ID primario) da entidade; 
 *          Caso falha, retorna -1;
 */
EntityHandle entity_Create(void);

/**
 * \brief Atualiza os dados de saude da entidade na estrutura de controle gtComponents.
 * \param tHealth Struct com as informações do handle e saude da entidade.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_UpdateHealth(t_Health * tHealth);

/**
 * \brief Atualiza os dados de posicionamento da entidade na estrutura de controle gtComponents.
 * \param tHealth Struct com as informações do handle e posição nova da entidade.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_UpdatePosition(t_Position * tPosition);

/**
 * \brief Obtem os dados de saude atual da entidade.
 * \param tHealth Struct para envio do handle e recebimento dos dados de saude.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_CheckHealth(t_Health * tHealth);

/**
 * \brief Obtem os dados de posicionamento atual da entidade.
 * \param tHealth Struct para envio do handle e recebimento dos dados de posição.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_CheckPosition(t_Position * tPosition);

#endif