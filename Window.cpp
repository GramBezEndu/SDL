#include "Window.h"

bool Window::running = true;

///Create window
Window::Window(char* name, int x, int y, int width, int height, int Fullscreen)
{
        ///Set screen width and heigth
        this -> SCREEN_WIDTH = width;
        this -> SCREEN_HEIGHT = height;
        ///Scale
        int w;
        int h;
        ///Success flag
        bool success = true;
        ///Init SDL
    	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
        {
            fprintf(Error::error, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        ///Initialize PNG images
        if (!IMG_INIT_PNG)
        {
            fprintf(Error::error, "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
        ///Initialize SDL_ttf
        if( TTF_Init() == -1 )
        {
            fprintf(Error::error, "TTF could not initialize! SDL_TTF Error: %s\n", TTF_GetError() );
            success = false;
        }
        ///Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            fprintf(Error::error, "Warning: Linear texture filtering not enabled!\n" );
        }
        ///Open Mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            fprintf(Error::error, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        ///Create window
            window = SDL_CreateWindow( name, x, y, this -> SCREEN_WIDTH, this -> SCREEN_HEIGHT,  SDL_WINDOW_SHOWN );
            SDL_GetWindowSize(window, &w, &h);
        if( window == NULL )
        {
            fprintf(Error::error, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success=false;
        }
        ///Set Fullscreen
        if (Fullscreen == 1)
        {
            if ( SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0 )
            {
                fprintf(Error::error, "Could not maximize window! %s\n", SDL_GetError() );
                success = false;
            }
            SDL_GetWindowSize(window, &w, &h);
        }
        ///Create renderer
        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE );
        if( renderer == NULL )
        {
            fprintf(Error::error, "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success=false;
        }

        ///Renderer scale
        SDL_RenderSetScale(renderer, 1, 1);
        ///Objects scaling
        SDL_RenderSetLogicalSize(renderer, 854, 480);

        this -> scale_width = w / (float)854;
        this -> scale_height = h / (float)480;

        ///Initialize renderer color
        SDL_SetRenderDrawColor( renderer, 0xff, 0xff, 0xff, 0xff );

        if (success == false)
        {
            Window::Quit();
        }
}

///Frees media and shuts down all SDL
Window::~Window()
{
	///Destroy window
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	///Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::IsRunning()
{
    return running;
}

void Window::Quit()
{
    running = false;
}
