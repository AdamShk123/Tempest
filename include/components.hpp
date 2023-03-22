#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Texture
{
    SDL_Texture *t;
};

struct Position
{
    int x;
    int y;
};

struct Velocity
{
    float dx;
    float dy;
};