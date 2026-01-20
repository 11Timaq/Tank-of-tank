#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int thirdTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2])
{
    static bool Tup = false;
    static bool Tdown = false;
    static bool Tleft = false; 
    static bool Tright = false;
    static int Tgo;
    static int Trandom_AI;
    static bool random = true;
    static bool algoritm = false;

    static Uint32 lastSwitch = 0;
    Uint32 now = SDL_GetTicks();

    if (now - lastSwitch >= 10000)
    {
        random = !random;
        algoritm = !algoritm;
        lastSwitch = now;
    }

    int Xcel = tank[2].x;
    int Ycel = tank[2].y;

    if (tank[1].x > 800 and tank[0].x < 800)
    {
        Xcel = tank[0].x;
        Ycel = tank[0].y;
    }

    if (tank[2].x > 800 and tank[1].x < 800)
    {
        Xcel = tank[1].x;
        Ycel = tank[1].y;
    }



    if(algoritm)
    {
        if(Xcel > tank[3].x)
        {
            if(tank[3].x != 0)
            {
                Tgo = 3;
                tank[3].x -= 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].x += 2;
                }
            }
        }

        else if(Xcel < tank[3].x)
        {
            if(tank[3].x != 560)
            {
                Tgo = 4;
                tank[3].x += 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].x -= 2;
                }
            }
        }

        else if(Ycel > tank[3].y)
        {
            if(tank[3].y != 0)
            {
                Tgo = 1;
                tank[3].y -= 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {    
                    tank[3].y += 2;
                }
            }
        }

        else if(Ycel < tank[3].y)
        {
            if(tank[3].y != 560)
            {
                Tgo = 2;
                tank[3].y += 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].y -= 2;
                }
            }
        }
    }    



    if(random)
    {
        int randomazer = rand() % 60;
    
        if(randomazer == 0)
        {
            Trandom_AI = 1 + rand() % 4;
        }

        if(Trandom_AI == 1)
        {
            Tgo = 1;

            if(tank[3].y != 0)
            {
                tank[3].y -= 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {    
                    tank[3].y += 2;
                }
            }
        }

        if(Trandom_AI == 2)
        {
            Tgo = 2;

            if(tank[3].y != 560)
            {
                tank[3].y += 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].y -= 2;
                }
            }
        }

        if(Trandom_AI == 3)
        {
            Tgo = 3;

            if(tank[3].x != 0)
            {
                tank[3].x -= 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].x += 2;
                }
            }
        }

        if(Trandom_AI == 4)
        {
            Tgo = 4;

            if(tank[3].x != 560)
            {
                tank[3].x += 2;
                if(SDL_HasRectIntersectionFloat(&tank[3], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[3], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[3], &wall[1]))
                {
                    tank[3].x -= 2;
                }
            }
        }
    }
    
    return Tgo;
}
