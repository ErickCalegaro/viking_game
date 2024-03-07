#ifndef __SCREEN_H__
#define __SCREEN_H__

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_font.h>
#include <SDL2/SDL_ttf.h>

#ifdef __INTELLISENSE__
    //Defines no Makefile
    #pragma diag_suppress 20
    #pragma diag_suppress 65
#endif

int screen_CreateWindow(void);

#endif