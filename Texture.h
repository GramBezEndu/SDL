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
        bool apply_texture(Window &, std::string, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1, int = -1);
        bool check_mouse_collision();
};

#endif // TEXTURE_H_INCLUDED
