#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// functions
bool loadMedia(SDL_Window *window);

SDL_Surface *loadSurface(std::string path, SDL_Surface *screenSurface);

SDL_Texture *loadTexture(std::string path, SDL_Renderer *renderer);