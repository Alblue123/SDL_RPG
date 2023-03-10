#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include "RenderWindow.h"
#include <iostream>

//Screen dimension constants
const int gWidth = 640;
const int gHeight = 480;

int main(int argc, char* argv[])
{
    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
	}
	//Initialize png loading
	if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout<< "IMG_INIT has failed! SDL Error: " << SDL_GetError() << std::endl;
    }
    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        std::cout<< "Warning: Linear texture filtering not enabled!" << std::endl;
    }
            //loop flag
            bool quit = false;

            WindowRender gWindow(gWidth, gHeight);
            SDL_Texture* chr = gWindow.loadedTexture("demonboy.png");

            //Even handler
            SDL_Event e;

            //While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				gWindow.clear();
				gWindow.render(chr);
				gWindow.display();
			}

     gWindow.free();

	//quit the subsytem
	IMG_Quit();
    SDL_Quit();
	return 0;
}


