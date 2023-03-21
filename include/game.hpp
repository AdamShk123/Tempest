#pragma once

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <iostream>

#include "window.hpp"

class Game
{
    private:
        Window *window;

    public:
        Game(Window *w);
        ~Game();

        void update();
};