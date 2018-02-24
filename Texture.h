#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <iostream>

#include "Window.h"

class Texture
{
    private:
        int x;
        int y;
        int w;
        int h;
    public:
        ///Camera position
        static int PosX;
        static int PosY;
        bool apply_texture(Window &, std::string, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1);
        bool check_mouse_collision();
        int getCameraPosX();
        int getCameraPosY();
        static void setCamera();
};

#endif // TEXTURE_H_INCLUDED
