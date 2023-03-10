#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

//the window we will be rendering to

class WindowRender
{

public:

    //Initialise variables
    WindowRender(int gWidth, int gHeight);
    SDL_Texture* loadedTexture(std::string path);

    //Destroy variables
    void free();

    //display render
    void render(SDL_Texture* gTexture);
    void clear();
    void display();

private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;

};

