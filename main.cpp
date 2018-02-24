#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Window.h"
#include "Config.h"
#include "Scene.h"
#include "Error.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ///Open error file
    if( !Error::check_error() )
    {
        return 1;
    }
    ///Read config
    Config config("config.txt");
    ///Create window
    Window MainWindow("Stupid Ass Game", config.WindowPosX, config.WindowPosY, config.ScreenWidth, config.ScreenHeight, config.Fullscreen);
    ///Actual scene
    Scene ActualScene(config.MusicVolume);
    ///Set starting scene to MAIN_MENU
    ActualScene.scene_number = Scene::MAIN_MENU;
    ///Main loop
    while ( Window::IsRunning() )
    {
        ///Load scenes
        if (ActualScene.scene_loaded == false)
        {
            ActualScene.load_scene(MainWindow);
        }
        ///Handle events
        ActualScene.handle_events(MainWindow);
        ///Update screen
        SDL_RenderPresent( MainWindow.renderer );
    }
    ///Quit
    Window::Quit();
    ///Destroy everything
    MainWindow.~Window();
    return 0;
}
