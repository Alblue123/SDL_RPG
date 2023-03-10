#include "RenderWindow.h"

WindowRender::WindowRender(int gWidth, int gHeight)
{
    //Initialise
    gWindow = NULL;
    gRenderer = NULL;

    //create window
    gWindow = SDL_CreateWindow( "Elpis Adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gWidth , gHeight , SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
		{
			std::cout << "Window could not be created! SDL Error:" << SDL_GetError() << std::endl;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				std::cout<< "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
			}
		}
}

SDL_Texture* WindowRender::loadedTexture(std::string path)
{
    //Initialise
    SDL_Texture* gTexture = NULL;

    //load img at specific path
    gTexture = IMG_LoadTexture(gRenderer, path.c_str());
    if( gTexture == NULL )
		{
			std::cout<< "Unable to create texture from: " << path.c_str() << ", " << SDL_GetError() << std::endl;
		}
    return gTexture;
}

void WindowRender::render(SDL_Texture* gTexture)
{
    //render to screen
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
}

void WindowRender::clear()
{
    //clear screen
    SDL_RenderClear(gRenderer);
}

void WindowRender::display()
{
    //Update screen
    SDL_RenderPresent(gRenderer);
}

void WindowRender::free()
{
     //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
}

