#pragma once

// libraries

// SDL
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h>

// UI
//#include "nuklear.h"

// ECS
#include "entt.hpp"

// Standard Library
#include <iostream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>

// header files
#include "media.hpp"
#include "components.hpp"
#include "window.hpp"
#include "game.hpp"
//#include "interface.hpp"

// externs
extern SDL_Texture *texture;

// struct Block
// {
//     int x;
//     int y;
// };

// // globals
// std::vector<Block> blocks;

// functions
SDL_Window *initWindow();

void close(SDL_Window *window);

void loadLevel(std::string path);