#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <cstdio>
#include <iostream>

#include "Config.h"
#include "Error.h"

class Window
{
    private:
        static bool running;
        SDL_Window* window;
        ///Scale
        float scale_width;
        float scale_height;
        ///Screen dimension
        int SCREEN_WIDTH;  ///ScreenWidth 854
        int SCREEN_HEIGHT; ///ScreenHeight 480
        ///Level dimension
        int Level_width; ///1200
        int Level_height; ///480
    public:
        ///Window
        SDL_Renderer* renderer;
        ///Create window
        Window(char*, int, int, int, int, int);
        ~Window();
        ///Running
        static bool IsRunning();
        ///Quit
        static void Quit();
        int getLevelWidth();
        int getLevelHeight();
        int getWindowWidth();
        int getWindowHeight();
};

#endif // WINDOW_H_INCLUDED
