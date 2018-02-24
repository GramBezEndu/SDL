#include "Character.h"

Texture body;

bool Character::apply_character(Window &obj, std::string _name, int x, int y, int w, int h, int x2, int y2, int w2, int h2)
{
    this -> name.assign(_name);
    this -> PosX = x;
    this -> PosY = y;
    this -> random.x = x2;
    this -> random.y = y2;
    this -> random.w = w2;
    this -> random.h = h2;
    if ( !body.apply_texture(obj, _name, random.x, random.y, random.w, random.h, x2, y2, w2, h2) )
        return false;
    return true;
}

/*bool Character::load_animations()
{
    return true;
}*/

void Character::Character_Controller(Window &obj)
{

    ///Texture - RenderCopy
    SDL_Texture* Texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load("../SDL_2018/textures/idle.png");
    if( loadedSurface == NULL )
	{
		fprintf(Error::error, "Unable to load image! SDL_image Error: %s\n", IMG_GetError() );
		//success = false;
	}
    ///Create texture from surface pixels
    Texture = SDL_CreateTextureFromSurface( obj.renderer, loadedSurface );
    if( Texture == NULL )
    {
        //fprintf(Error::error, "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        //success = false;
    }
    ///Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    /*///newTexture - RenderTarget
    SDL_Texture* newTexture = SDL_CreateTexture(obj.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 854, 480);*/


    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0 )
    {
         if( event.type == SDL_QUIT )
        {
            Window::Quit();
        }
        if ( event.type == SDL_KEYDOWN )
        {
            switch ( event.key.keysym.sym )
            {
                 case SDLK_RIGHT:
                    if ( PosX+5 <= obj.getLevelWidth() )
                    {
                        this -> PosX+=5;
                    }
                    random.x = PosX;
                    //SDL_SetRenderTarget(obj.renderer, newTexture);
                    //SDL_RenderClear(obj.renderer);
                    //SDL_RenderCopy(obj.renderer, newTexture, &random, &random);
                    //body.apply_texture(obj, "idle.png", PosX, 348 ,34 ,75, 5, 14, 23, 50);
                    //SDL_RenderClear(obj.renderer);
                    SDL_RenderCopy(obj.renderer, Texture, NULL, &random);
                    std::cout << "right: PosX= " << this -> PosX << '\n';
                    break;

                case SDLK_LEFT:
                    //SDL_SetRenderTarget(obj.renderer, newTexture);
                    if ( PosX-5 >= 10 )
                    {
                        this -> PosX-=5;
                    }
                    random.x = PosX;
                    //SDL_SetRenderTarget(obj.renderer, newTexture);
                    //SDL_RenderClear(obj.renderer);
                    //SDL_SetRenderTarget(obj.renderer, NULL);
                    //SDL_RenderClear(obj.renderer);
                    //SDL_RenderClear(obj.renderer);
                    //SDL_RenderCopy(obj.renderer, Texture, NULL, &random);
                    //SDL_RenderPresent(obj.renderer);
                    //body.apply_texture(obj, "idle.png", PosX, 348 ,34 ,75, 5, 14, 23, 50);
                    ///Detach
                    //SDL_SetRenderTarget(obj.renderer, NULL);
                    //SDL_RenderClear(obj.renderer);
                    //SDL_RenderCopy(obj.renderer, Texture, NULL, &random);
                    SDL_RenderCopyEx(obj.renderer, Texture, NULL, &random, 0, NULL, SDL_FLIP_HORIZONTAL);
                    std::cout << "left: PosX= " <<  this -> PosX << " PosY= " << this -> PosY << '\n';
                    break;

                default:
                    break;
            }
        }
    }
}
