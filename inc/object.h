#ifndef __OBJECT_H__
#define __OBJECT_H__
/*****************************************************************************
 * Includes
 *****************************************************************************/

/*****************************************************************************
 * Preprocessor Macros and Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedefs and Variable Definitions
 *****************************************************************************/
typedef struct {
    int iPosX;
    int iPosY;
    SDL_Rect        tSourceRect;
    SDL_Rect        tDestRect;
    SDL_Texture    *ptTexture;
    SDL_Renderer   *ptRenderer;
} t_GameObject;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

e_Ret object_Create(t_GameObject * ptGameObject, const char *TextureSheet, SDL_Renderer * ptRenderer, int iPosX, int iPosY);

e_Ret object_Update(t_GameObject * ptGameObject);

e_Ret object_Render(t_GameObject * ptGameObject);

#endif