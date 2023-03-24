#include "../include/input.hpp"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

std::string InputManager::checkEvents(SDL_Event *e)
{
    std::string event;

    if(e->type == SDL_KEYDOWN && e->key.repeat == 0)
    {
        switch(e->key.keysym.sym)
        {
            case SDLK_w: event = "up"; break;
            case SDLK_s: event = "down"; break;
            case SDLK_a: event = "left"; break;
            case SDLK_d: event = "right"; break;
        }
    }

    return event;
}





