#include "../include/window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

Window::Window()
{
    initWindow();
}

Window::~Window()
{
    close();
}

SDL_Window *Window::getWindow()
{
    return window;
}

SDL_Renderer *Window::getRenderer()
{
    return renderer;
}

void Window::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Window::draw(SDL_Texture *texture, SDL_Rect *rect, SDL_Rect *clipRect)
{
    SDL_RenderCopy(renderer, texture, clipRect, rect);
}

void Window::render()
{
    //Update screen
	SDL_RenderPresent(renderer);
}

void Window::initWindow()
{
    SDL_Window *window = NULL;

    // init SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    }
    else
    {
        // create window
        window = SDL_CreateWindow("Tempest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
        if(window == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            }
            else
            {
                int imgFlags = IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << "\n";
                }
            }
        }
    }
}

void Window::close()
{
	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


