#pragma once

// libraries

// SDL
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <SDL2/SDL_mixer.h>

// UI
#include "nuklear.h"

// ECS
#include "entt.hpp"

// Standard Library
#include <iostream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>

// header files
#include "media.hpp"

// externs
extern SDL_Texture *texture;

// screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

entt::scheduler<uint32_t> scheduler;

// same as declaring entt::basic_registry<uint32_t> registry;
entt::basic_registry<uint32_t> registry;

// functions
SDL_Window *initWindow();

void close(SDL_Window *window);