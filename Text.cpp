#include "Window.h"
#include "Text.h"

bool Text::apply_text(Window &obj, std::string _text, int x, int y)
{
    TTF_Font* font = TTF_OpenFont("../SDL_2018/ttf/Roboto-Black.ttf", 32);
    SDL_Color color = {255, 255, 255, 0};
    bool success = true;
    int w, h;
    SDL_Rect random;
    random.x = x;
    random.y = y;
    ///String to char*
    const char* NewText = &_text[0u];
    ///Get w, h
    TTF_SizeText(font, NewText, &w, &h);
    this -> w = w;
    this -> h = h;
    random.w = this -> w;
    random.h = this -> h;
    if ( font == NULL)
    {
        fprintf(Error::error, "Font was not loaded!\n");
        success = false;
    }
    this -> textSurface=TTF_RenderText_Solid( font, NewText, color );
    if(this -> textSurface == NULL)
    {
        fprintf(Error::error,"Could not render text! TTF Error: %s\n", TTF_GetError() );
        success=false;
    }
    ///Convert textSurface to normal texture
    SDL_Texture *text = SDL_CreateTextureFromSurface( obj.renderer, textSurface );
    if ( text == NULL )
    {
        fprintf(Error::error, "Could not create texture! TTF Error: %s\n", TTF_GetError() );
        success=false;
    }
    SDL_FreeSurface( textSurface );

    if ( SDL_RenderCopy( obj.renderer, text, NULL, &random)!=0 )
    {
        fprintf(Error::error, "Could not show text! SDL Error: %s\n", SDL_GetError() );
        success=false;
    }
    if ( success == false )
    {
        Window::Quit();
    }
}

