#include "Config.h"

Config::Config(char* name)
{
    std::string parametr;
    int number;
    std::fstream file(name);
    ///File did not open
    if ( !file.is_open() )
    {
        fprintf(Error::error, "Could not open config file!\n" );
    }
    while(!file.eof())
    {
        file >> parametr;
        file >> number;
        if ( parametr.compare("ScreenWidth") == 0)
        {
            this -> ScreenWidth = number;
        }

        if ( parametr.compare("ScreenHeight") == 0)
        {
            this -> ScreenHeight = number;
        }

         if ( parametr.compare("WindowPosX") == 0)
        {
            this -> WindowPosX = number;
        }

         if ( parametr.compare("WindowPosY") == 0)
        {
            this -> WindowPosY = number;
        }
         if ( parametr.compare("Fullscreen") == 0)
        {
            this -> Fullscreen = number;
        }
         if ( parametr.compare("MusicVolume") == 0)
        {
            this -> MusicVolume = number;
        }
    }
}
