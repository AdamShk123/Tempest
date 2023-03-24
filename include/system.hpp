  #pragma once

#include <SDL2/SDL.h>

#include "entt.hpp"
#include "components.hpp"
#include "window.hpp"

class System
{
    private:

    public:
        virtual void update(entt::registry *registry) = 0;
};

class MoveSystem : public System
{
    private:

    public:
        MoveSystem();
        void update(entt::registry *registry);
};

class DrawSystem : public System
{
    private:
        Window *window;

    public:
        DrawSystem(Window *w);
        void update(entt::registry *registry);
};