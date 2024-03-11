/**
 * \file    screen.c
 * \version 0.0.1
 * \date    07/03/2024
 * \author  Erick Calegaro
 */

/*****************************************************************************
 * Includes
 *****************************************************************************/

#include "main.h"
#include "screen.h"
#include "control.h"

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/


/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/

static int              giCount = 0;
static SDL_Window      *gptWindow;
SDL_Renderer           *gptRenderer;

// Caracteristicas do personagem
t_GameObject gtPlayerObject;

// Caracteristicas do inimigo
t_GameObject gtEnemyObject;

/*****************************************************************************
 * Private Function Prototypes
 *****************************************************************************/

/**
 * \brief Pinta a tela com a cor de fundo default.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
static e_Ret screen_DrawBackground(void); 

/**
 * \brief Cria a textura do personagem principal.
 * \param void
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
static e_Ret screen_CreatePlayer(void);

/**
 * \brief Cria a textura do inimigo da fase.
 * \param void // !TODO: Passar e_State como parametro para alterar o asset
 * \returns RET_OK - Caso sucesso; 
 *          RET_SDL_ERROR - Caso falhe; 
 */
static e_Ret screen_CreateEnemy(void);

/*****************************************************************************
 * Private Function Definitions
 *****************************************************************************/

static e_Ret screen_DrawBackground(void)
{
    e_Ret eRet = RET_OK;
    eRet = SDL_SetRenderDrawColor(gptRenderer, 255, 120, 97, 255);
    if (eRet < 0) {
        printf("Nao foi possivel definir a cor de fundo! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    eRet = screen_Render();
    if (eRet < 0) {
        printf("Nao foi possivel renderizar a tela!\n");
        return RET_SDL_ERROR;
    }

    return RET_OK;
}

static e_Ret screen_CreatePlayer(void)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;
    
    memset(&gtPlayerObject, 0x00, sizeof(gtPlayerObject));

    eRet = object_Create(&gtPlayerObject, TEXTURE_PLAYER, 0, 0);
    if (eRet){
        printf("Nao foi possivel criar o objeto Player!\n");
        return RET_INIT_ERROR;
    }

    ghPlayerHandle = entity_Create();
    if (ghPlayerHandle < RET_OK){
        printf("Nao foi possivel criar a entidade Player!\n");
        return RET_INIT_ERROR;
    }

    tTempPosition.hEntityID = ghPlayerHandle;
    tTempPosition.iPosX     = 1;
    tTempPosition.iPosY     = 1;
    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir posicoes iniciais para entidade!\n");
        return RET_POS_ERROR;
    }
    
    return RET_OK;
}

static e_Ret screen_CreateEnemy(void)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;
    
    memset(&gtEnemyObject, 0x00, sizeof(gtEnemyObject));
    
    eRet = object_Create(&gtEnemyObject, TEXTURE_WOLF, 50, 50);
    if (eRet){
        printf("Nao foi possivel criar o objeto Enemy!\n");
        return RET_INIT_ERROR;
    }

    ghEnemyHandle = entity_Create();
    if (ghEnemyHandle < RET_OK){
        printf("Nao foi possivel criar a entidade Enemy!\n");
        return RET_INIT_ERROR;
    }

    tTempPosition.hEntityID = ghEnemyHandle;
    tTempPosition.iPosX     = SCREEN_WIDTH;
    tTempPosition.iPosY     = 1;
    eRet = entity_UpdatePosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel definir posicoes iniciais para entidade!\n");
        return RET_POS_ERROR;
    }
    
    return RET_OK;
}


/*****************************************************************************
 * Public Function Definitions
 *****************************************************************************/

e_Ret screen_InitSDL(void)
{ 
    if (TTF_Init() < 0) {
        printf("Fontes nao puderam ser inicializadas! TTF_Error: %s\n", TTF_GetError());
        return RET_INIT_ERROR;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL nao pode ser inicializado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    return RET_OK;
}

e_Ret screen_CreateWindow(bool bFullscreen) 
{
    char sTitle[] = APP_NAME " - " VERSION;
    int iFlags = SDL_WINDOW_SHOWN;
    
    if (bFullscreen){
        iFlags = SDL_WINDOW_FULLSCREEN;
    }

    gptWindow = SDL_CreateWindow(sTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, iFlags);
    if (gptWindow == NULL) {
        printf("Janela nao pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }
    
    gptRenderer = SDL_CreateRenderer(gptWindow, -1, 0);
    if (gptRenderer == NULL) {
        printf("Renderizador nao pode ser criado! SDL_Error: %s\n", SDL_GetError());
        return RET_INIT_ERROR;
    }

    if (screen_DrawBackground()) {
        printf("Nao foi possivel desenhar o BG!\n");
        return RET_INIT_ERROR;
    }

    if (screen_CreatePlayer()){
        printf("Textura do jogador nao pode ser criada!\n");
        return RET_INIT_ERROR;
    }

    if (screen_CreateEnemy()){
        printf("Textura do inimigo nao pode ser criada!\n");
        return RET_INIT_ERROR;
    }

    return RET_OK;
}

e_Ret screen_Update(void)
{
    e_Ret eRet = RET_OK;
    t_Position tTempPosition;
    giCount++;

    //Posição do jogador
    tTempPosition.hEntityID = ghPlayerHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }
    eRet = object_Update(&gtPlayerObject, &tTempPosition);
    if (eRet){
        printf("Nao foi possivel atualizar o objeto Player!\n");
        return RET_OBJ_ERROR;
    }

    //Posição do inimigo
    tTempPosition.hEntityID = ghEnemyHandle;
    eRet = entity_CheckPosition(&tTempPosition);
    if (eRet){
        printf("Nao foi possivel obter as posicoes da entidade!\n");
        return RET_POS_ERROR;
    }
    eRet = object_Update(&gtEnemyObject, &tTempPosition);
    if (eRet){
        printf("Nao foi possivel atualizar o objeto Enemy!\n");
        return RET_OBJ_ERROR;
    }

    // printf("giCount = [%d]\n", giCount);
    return eRet;
}

e_Ret screen_Render(void)
{
    e_Ret eRet = RET_OK;

    //Limpa a tela
    eRet = SDL_RenderClear(gptRenderer);
    if (eRet < 0) {
        printf("Nao foi possivel limpar o render! SDL_Error: %s\n", SDL_GetError());
        return RET_SDL_ERROR;
    }

    //Renderiza o Mapa
    eRet = map_Draw();
    if (eRet){
        printf("Nao foi possivel desenhar o mapa!\n");
        return RET_INIT_ERROR;
    }

    //Renderiza o jogador
    eRet = object_Render(&gtPlayerObject);
    if (eRet){
        printf("Nao foi possivel renderizar o objeto Player!\n");
        return RET_INIT_ERROR;
    }

    //Renderiza o inimigo
    eRet = object_Render(&gtEnemyObject);
    if (eRet){
        printf("Nao foi possivel renderizar o objeto Enemy!\n");
        return RET_INIT_ERROR;
    }

    //Atualiza o Render
    SDL_RenderPresent(gptRenderer); 

    return RET_OK;
}

e_Ret screen_DestroySDL(void)
{ 
    SDL_DestroyWindow(gptWindow);

    SDL_DestroyRenderer(gptRenderer);

    SDL_Quit();

    return RET_OK;
}