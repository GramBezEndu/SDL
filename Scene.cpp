#include "Scene.h"

///Menu
Texture MenuBackground;
Texture Button[2];
Text Start;
Text Settings;
Text Exit;

///Game
Character character;
Texture GameBackground;
Texture Surface;
Texture Tree;
Texture Trash;
Texture Box;
Texture Trolley;
Texture Boombox;

    bool Scene::scene_loaded = false;

Scene::Scene(int volume)
{
    this -> MusicVolume = volume;
}

void Scene::load_scene(Window &obj)
{
    switch(this -> scene_number)
    {
        case Scene::MAIN_MENU:
            ///Open mixer
            if ( !Mix_VolumeMusic(this -> MusicVolume) )
            {
                fprintf(Error::error, "Scene: Could not set VolumeMusic!\n");
                Window::Quit();
            }
            ///Load Main theme music
            if ( !this -> load_music("Undertale OST 006 - Uwa!! So Temperate.mp3") )
            {
                fprintf(Error::error, "Scene: Could not load music!\n");
                Window::Quit();
            }
            ///Play music
            if ( !this -> play_music())
            {
                fprintf(Error::error, "Could not play music!\n");
                Window::Quit();
            }
            ///Background
            if( !MenuBackground.apply_texture(obj, "background.jpg") )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            for (int i=0; i<3 ; i++)
            {
                ///Button
                if( !Button[i].apply_texture(obj, "button.png", 20, 100+(70*i), 200, 68, 0, 0 , 630, 203) )
                {
                    fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                    Window::Quit();
                }
            }
            ///Start text
            if ( !Start.apply_text(obj, "START", 70, 110) )
            {
                fprintf(Error::error, "Scene: Could not apply text!\n");
                Window::Quit();
            }
            ///Settings text
            if ( !Settings.apply_text(obj, "SETTINGS", 45, 180) )
            {
                fprintf(Error::error, "Scene: Could not apply text!\n");
                Window::Quit();
            }
            ///Exit text
            if ( !Exit.apply_text(obj, "EXIT", 80, 250) )
            {
                fprintf(Error::error, "Scene: Could not apply text!\n");
                Window::Quit();
            }
            this -> scene_loaded = true;
            return;
            break;
        case Scene::SETTINGS:
            if( !GameBackground.apply_texture(obj, "night_background.png") )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            return;
            break;
        case Scene::GAME:
            ///Background
            if( !GameBackground.apply_texture(obj, "night_background.png") )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            for (int i=0; i<20;i++)
            {
                ///Surface
                if ( !Surface.apply_texture(obj, "25 - 5ujCdBq.png", (i*60), 420, 85, 60, 35, 3, 85, 60) )
                {
                    fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                    Window::Quit();
                }
            }
            ///Tree
            if ( !Tree.apply_texture(obj, "36 - Ci3L3sm.png", 40, 305, 100, 120, 410, 170, 100, 120) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            ///Trash
            if ( !Trash.apply_texture(obj, "22 - akVMFuI.png", 120, 340, 256, 82, 1, 420, 256, 82) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            ///Box
            if ( !Box.apply_texture(obj, "11 - eRrO0qf.png", 190, 395, 90, 30, 260, 100, 91, 30) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            ///Trolley
            if ( !Trolley.apply_texture(obj, "11 - eRrO0qf.png", 375, 390, 30, 35, 80, 65, 35, 30) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            ///Boombox
            if ( !Boombox.apply_texture(obj, "11 - eRrO0qf.png", 615, 390, 40, 40, 33, 10, 35, 40) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            ///Player
            if ( !character.apply_character(obj, "idle.png", 740, 148 ,34 ,75, 5, 14, 23, 50) )
            {
                fprintf(Error::error, "Scene: Could not apply texture! %s\n", SDL_GetError() );
                Window::Quit();
            }
            this -> scene_loaded = true;
            return;
            break;
        default:
            return;
            break;
    }
}

bool Scene::handle_events(Window &obj)
{
            switch(this -> scene_number)
            {
                case Scene::MAIN_MENU:

                SDL_Event event;
                while( SDL_PollEvent( &event ) != 0 )
                    {
                        if( event.type == SDL_QUIT )
                        {
                            Window::Quit();
                        }
                        if (Button[0].check_mouse_collision() )
                        {
                            //std::cout << "Y\n";
                            if (event.type == SDL_MOUSEBUTTONDOWN)
                            {
                                    this -> scene_number = Scene::GAME;
                                    this -> scene_loaded = false;
                            }
                        }
                        if ( Button[1].check_mouse_collision() )
                        {
                            if (event.type == SDL_MOUSEBUTTONDOWN)
                            {
                                    this -> scene_number = Scene::SETTINGS;
                                    this -> scene_loaded = false;
                            }
                        }
                        if ( Button[2].check_mouse_collision() )
                        {
                            if (event.type == SDL_MOUSEBUTTONDOWN)
                            {
                                    ///Quit game
                                    Window::Quit();
                            }
                        }
                    }
                    break;

                case Scene::GAME:

                    character.Character_Controller(obj);
                    //SDL_BlitSurface();
                    break;
                default:
                    break;
            }
        return true;
}

bool Scene::load_music(std::string _name)
{
    bool success = true;
    std::string path="../SDL_2018/music/";
    std::string name2;
    name2.append(path);
    name2.append(_name);
    ///String to char*
    this -> name=&name2[0u];

    music = Mix_LoadMUS( name );
	if( music == NULL )
	{
		fprintf(Error::error, "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	return success;
}

bool Scene::play_music()
{
    if(Mix_PlayMusic(this -> music, -1) == -1)
    {
        fprintf(Error::error, "Mix_PlayMusic: %s\n", Mix_GetError());
        return false;
    }
	return true;
}
