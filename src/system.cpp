#include "../include/system.hpp"

// Move System
MoveSystem::MoveSystem()
{

}

void MoveSystem::update(entt::registry *registry)
{
    auto list = registry->view<Position, Velocity>();

    for(auto index : list)
    {
        auto v = registry->get<Velocity>(index);
        auto p = registry->get<Position>(index);
        p.x += v.dx;
        p.y += v.dy;
        registry->replace<Position>(index,p);
    }
}

// Draw System
DrawSystem::DrawSystem(Window *w)
{
    window = w;
}

void DrawSystem::update(entt::registry *registry)
{
    SDL_Rect rect;
    auto list2 = registry->view<Position, Texture>();
    for(auto index : list2)
    {
        auto t = registry->get<Texture>(index).t;
        rect.x = registry->get<Position>(index).x;
        rect.y = registry->get<Position>(index).y;
        int w,h;
        SDL_QueryTexture(registry->get<Texture>(index).t,NULL, NULL, &w, &h);
        rect.w = w;
        rect.h = h;
        window->draw(t,&rect);
    }
}