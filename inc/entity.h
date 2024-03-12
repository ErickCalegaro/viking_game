#ifndef __ENTITY_H__
#define __ENTITY_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/


/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

#define MAX_COMPONENTS 100
#define SPEED          3

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
    int             iHeight;
    int             iWidth;
} t_Scale;

typedef struct {
    EntityHandle    hEntityID;
    int             iCurrHealth;
    int             iMaxHealth;
} t_Health;

typedef struct {
    EntityHandle    hEntityID;
    int             iVelocityX;
    int             iVelocityY;
} t_Velocity;

typedef struct {
    t_Health    atHealthComponents   [MAX_COMPONENTS];
    t_Position  atPositionComponents [MAX_COMPONENTS];
    t_Scale     atScaleComponents    [MAX_COMPONENTS];
    int         iTotalHealthComponents;
    int         iTotalPositionComponents;
    int         iTotalScaleComponents;
} t_ComponentLists;

extern EntityHandle ghPlayerHandle;
extern EntityHandle ghEnemyHandle;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/**
 * \brief Inicializa o modulo de componentes e zera gtComponents
 * \param void
 * \returns void
 */
void entity_Init(void);

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
 * \brief Atualiza os dados de posicionamento da entidade na estrutura de controle gtComponents, 
 *          com base em um atributo da direcional passado por parâmetro.
 * \param ptVelocity Struct com as informações do handle e velocidade de movimento.
 * \returns RET_OK - Caso sucesso; 
 *          RET_INV_PARAM - Caso receba um handle inválido;
 *          RET_POS_ERROR - Caso falhe na obtenção da posição da entidade; 
 */
e_Ret entity_UpdateVelocity(t_Velocity * ptVelocity);

e_Ret entity_UpdateScale(t_Scale * ptScale);

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

e_Ret entity_CheckScale(t_Scale * ptScale);

#endif