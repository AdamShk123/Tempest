#pragma once

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <iostream>

#include "media.hpp"

// screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

class Window
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        Window();
        ~Window();

        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();

        void initWindow();
        void close();

        void clear();
        void draw(SDL_Texture *texture, SDL_Rect *rect, SDL_Rect *clipRect = NULL);
        void render();

};
