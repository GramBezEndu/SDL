#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "Scene.h"

class Character
{
    private:
        int PosX;
        int PosY;
        ///Image source
        std::string name;
        ///x y w h
        SDL_Rect random;
    public:
        bool apply_character(Window &, std::string , int, int, int, int, int, int, int, int);
        //static bool load_animations();
        void Character_Controller(Window &);
};

#endif // CHARACTER_H_INCLUDED
