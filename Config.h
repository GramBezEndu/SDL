#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;
#include "Error.h"

class Config
{
public:
    int ScreenWidth;
    int ScreenHeight;
    int WindowPosX;
    int WindowPosY;
    int VSync;//
    int Fullscreen;
    int FrameRateLimit;//
    int MouseSensitivity;//
    int InvertY;//
    int MusicVolume;
    int SoundVolume;//
    Config(char*);
    //~Config();
};

#endif // CONFIG_H_INCLUDED
