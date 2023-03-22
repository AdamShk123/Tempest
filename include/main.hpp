#pragma once

// libraries

// SDL
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h>

#include <SDL2/SDL_ttf.h>

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
#include "system.hpp"

// externs
extern SDL_Texture *texture;

// functions
//void loadLevel(std::string path);