#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int firstTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2])
{
    static bool Fshoot = false;
    static bool Fogon = false;
    static bool Fup = false;
    static bool Fdown = false;
    static bool Fleft = false; 
    static bool Fright = false;
    static int Fgo = 0;
    static int random_AI;

    int randomazer = rand() % 30;
    
    if(randomazer == 0)
    {
        if(Fshoot == false)
        {
            random_AI = 1 + rand() % 5;
        }

        if(Fshoot or Fgo == 0)
        {
            random_AI = 1 + rand() % 4;
        }
    }

    if(random_AI == 1)
    {
        Fgo = 1;

        if(tank[1].y != 0)
        {
            tank[1].y -= 2;
            if(SDL_HasRectIntersectionFloat(&tank[1], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[1]))
            {    
                tank[1].y += 2;
            }
        }
    }

    if(random_AI == 2)
    {
        Fgo = 2;

        if(tank[1].y != 560)
        {
            tank[1].y += 2;
            if(SDL_HasRectIntersectionFloat(&tank[1], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[1]))
            {
                tank[1].y -= 2;
            }
        }
    }

    if(random_AI == 3)
    {
        Fgo = 3;

        if(tank[1].x != 0)
        {
            tank[1].x -= 2;
            if(SDL_HasRectIntersectionFloat(&tank[1], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[1]))
            {
                tank[1].x += 2;
            }
        }
    }

    if(random_AI == 4)
    {
        Fgo = 4;

        if(tank[1].x != 560)
        {
            tank[1].x += 2;
            if(SDL_HasRectIntersectionFloat(&tank[1], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[1], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[1], &wall[1]))
            {
                tank[1].x -= 2;
            }
        }
    }

    if(random_AI == 5)
    {
        Fshoot = true;
        Fogon = true;
    }

    if(Fshoot)
    {
        if(Fogon)
        {
            bullet.x = tank[1].x + 15;
            bullet.y = tank[1].y + 15;

            if(Fgo == 1)
            {
                Fup = true;
            }

            if(Fgo == 2)
            {
                Fdown = true;
            }

            if(Fgo == 3)
            {
                Fleft = true;
            }

            if(Fgo == 4)
            {
                Fright = true;    
            }
        }
        Fogon = false;

        if(Fup)
        {
            bullet.y -= 5;
        }

        if(Fdown)
        {
            bullet.y += 5;
        }

        if(Fleft)
        {
            bullet.x -= 5;
        }

        if(Fright)
        {
            bullet.x += 5;
        }

        if(bullet.y < -10 or bullet.y > 600 or bullet.x < -10 or bullet.x > 600)
        {
            Fshoot = false;
            Fogon = false;
            Fup = false;
            Fdown = false;
            Fleft = false;
            Fright = false;
        }
    }

    return Fgo;
}
