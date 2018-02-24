#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "Window.h"
#include "Texture.h"
#include "Text.h"
#include "Character.h"

class Scene
{
    private:
        Mix_Music* music;
        ///Music name
        char* name;
    public:
        ///Music
        bool load_music(std::string);
        bool play_music();
        int MusicVolume;
        ///Scene
        static bool scene_loaded;
        enum SCENE_NUMBER
        {
            MAIN_MENU,
            SETTINGS,
            GAME
        };
        SCENE_NUMBER scene_number;
        Scene(int);
        void load_scene(Window &);
        bool handle_events(Window &);
};

#endif // SCENE_H_INCLUDED
