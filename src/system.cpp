#include "../include/system.hpp"
#include <SDL2/SDL_rect.h>
#include <cmath>

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

// Collision System
CollisionSystem::CollisionSystem()
{

}

void CollisionSystem::update(entt::registry *registry)
{
    auto list = registry->view<Position,Velocity>();
    for(auto index : list)
    {
        SDL_FRect a, b;
        
        Position p = registry->get<Position>(index);
        Size s = registry->get<Size>(index);
        Velocity v = registry->get<Velocity>(index);

        a.x = p.x - v.dx; 
        a.y = p.y - v.dy;
        a.w = s.x; 
        a.h = s.y;
         
        b.x = 500;
        b.y = 500;
        b.w = 100;
        b.h = 100;

        a.x += v.dx;
        bool checkX = checkCollision(a,b);
        std::cout << a.x << "\n";
        if(checkX)
        {
            a.x -= v.dx;
            if(a.x < b.x)
            {
                a.x = b.x - a.w;
            }
            else
            {
                a.x = b.x + b.w;
            }
            v.dx = 0;
        }
        
        std::cout << a.x << "\n";

        a.y += v.dy;
        bool checkY = checkCollision(a,b);
        
        if(checkY)
        {
            a.y -= v.dy;
             if(a.y < b.y)
            {
                a.y = b.y - a.h;
            }
            else
            {
                a.y = b.y + b.h;
            }

            v.dy = 0;
        }
        registry->replace<Position>(index,a.x,a.y);
        registry->replace<Velocity>(index,v.dx,v.dy);
    }
}

bool CollisionSystem::checkCollision(SDL_FRect a, SDL_FRect b)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;
    //calculate sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //calculate sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(bottomA <= topB)
    {
        return false;
    }

    if(topA >= bottomB)
    {
        return false;
    }

    if(rightA <= leftB)
    {
        return false;
    }

    if(leftA >= rightB)
    {
        return false;
    }

    return true;
}

// Draw System
DrawSystem::DrawSystem(Window *w)
{
    window = w;
}

void DrawSystem::update(entt::registry *registry)
{
    SDL_Rect rect;
    auto list = registry->view<Position, Texture>();
    for(auto index : list)
    {
        auto t = registry->get<Texture>(index).t;
        rect.x = (int)registry->get<Position>(index).x;
        rect.y = (int)registry->get<Position>(index).y;
        int w,h;
        SDL_QueryTexture(registry->get<Texture>(index).t,NULL, NULL, &w, &h);
        rect.w = w;
        rect.h = h;
        window->draw(t,&rect);
    }
}
