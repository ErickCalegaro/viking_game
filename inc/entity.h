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
    EntityHandle    hEntityID;
    int             iPosX;
    int             iPosY;
} t_Position;

typedef struct {
    EntityHandle    hEntityID;
    int             iCurrHealth;
    int             iMaxHealth;
} t_Health;

typedef struct {
    t_Health    atHealthComponents   [MAX_COMPONENTS];
    t_Position  atPositionComponents [MAX_COMPONENTS];
    int         iTotalHealthComponents;
    int         iTotalPositionComponents;
} t_ComponentLists;

extern EntityHandle ghPlayerHandle;
extern EntityHandle ghEnemyHandle;

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
 * \param ptHealth Struct com as informações do handle e saude da entidade.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_UpdateHealth(t_Health * ptHealth);

/**
 * \brief Atualiza os dados de posicionamento da entidade na estrutura de controle gtComponents.
 * \param ptPosition Struct com as informações do handle e posição nova da entidade.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_UpdatePosition(t_Position * ptPosition);

/**
 * \brief Obtem os dados de saude atual da entidade.
 * \param ptHealth Struct para envio do handle e recebimento dos dados de saude.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_CheckHealth(t_Health * ptHealth);

/**
 * \brief Obtem os dados de posicionamento atual da entidade.
 * \param ptPosition Struct para envio do handle e recebimento dos dados de posição.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 */
e_Ret entity_CheckPosition(t_Position * ptPosition);

#endif