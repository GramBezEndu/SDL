#include "Texture.h"

int Texture::PosX = 0;
int Texture::PosY = 0;

///Apply texture (name, dstrect, source)
bool Texture::apply_texture(Window &obj, std::string _name, int x, int y, int w, int h, int x2, int y2, int w2, int h2)
{
    ///Save x, y, w, h
    this -> x = x;
    this -> y = y;
    this -> w = w;
    this -> h = h;

    ///Loading success flag
	bool success = true;

    ///Destination Rect
    SDL_Rect dstrect;
    dstrect.x=x - PosX;
    dstrect.y=y - PosY;
    dstrect.w=w;
    dstrect.h=h;

    ///Source Rect
    SDL_Rect source;
    source.x=x2;
    source.y=y2;
    source.w=w2;
    source.h=h2;

    ///Texture name+path
    std::string path="../SDL_2018/textures/";
    std::string name_path;
    name_path.append(path);
    name_path.append(_name);

    const char* name = name_path.c_str();

    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(name);
    if( loadedSurface == NULL )
	{
		fprintf(Error::error, "Unable to load image! SDL_image Error: %s\n", IMG_GetError() );
		success = false;
	}
    ///Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( obj.renderer, loadedSurface );
    if( newTexture == NULL )
    {
        fprintf(Error::error, "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        success = false;
    }
    ///Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    ///Render texture to screen
    if(x==-1 && y==-1 && w==-1 && h==-1 && x2==-1 && y2==-1 && w2==-1 && h2==-1)
    {
        if ( SDL_RenderCopy( obj.renderer, newTexture, NULL, NULL )!=0)
        {
            fprintf(Error::error, "Could not show texture! SDL Error: %s\n", SDL_GetError() );
            success=false;
        }
    }
    else if( x==-1 && y==-1 && w==-1 && h==-1)
    {
        if ( !SDL_RenderCopy( obj.renderer, newTexture, &source, NULL )!=0 )
        {
            fprintf(Error::error, "Could not show texture! SDL Error: %s\n", SDL_GetError() );
            success=false;
        }
    }
    else if( x==-1 && y==-1 && w==-1 && h==-1)
    {
        if ( SDL_RenderCopy( obj.renderer, newTexture, NULL, &dstrect)!=0 )
        {
            fprintf(Error::error, "Could not show texture! SDL Error: %s\n", SDL_GetError() );
            success=false;
        }
    }
    else
    {
        if ( SDL_RenderCopy( obj.renderer, newTexture, &source, &dstrect )!=0 )
        {
            fprintf(Error::error, "Could not show texture! SDL Error: %s\n", SDL_GetError() );
            success=false;
        }
    }
	if (success == false)
    {
        Window::Quit();
    }
    return success;
}

///Check mouse collision
bool Texture::check_mouse_collision()
{
    int _x, _y;
    SDL_GetMouseState(&_x, &_y);

    ///Mouse is left of the button
    if( _x < this -> x )
    {
        return false;
    }
    ///Mouse is right of the button
    if( _x > this -> x + this -> w )
    {
        return false;
    }
    ///Mouse above the button
    if( _y <  this -> y )
    {
        return false;
    }
    ///Mouse below the button
    if( _y >  this -> y + this -> h )
    {
        return false;
    }
    //printf("Y");
    return true;
}

int Texture::getCameraPosX()
{
    return this -> PosX;
}

int Texture::getCameraPosY()
{
    return this -> PosY;
}

void Texture::setCamera()
{
    //Camera.x = 200;
    //Camera.y = 0;
}

