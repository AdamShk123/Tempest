#pragma once

#include <SDL2/SDL.h>

#include <string>
#include <vector>

class InputManager
{
    private:

    public:
        InputManager();
        ~InputManager();
        std::string checkEvents(SDL_Event *e);
};