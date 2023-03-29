#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Texture
{
    SDL_Texture *t;
};

struct Position
{
    float x;
    float y;
};

struct Velocity
{
    float dx;
    float dy;
};

struct Size
{
    int x;
    int y;
};
