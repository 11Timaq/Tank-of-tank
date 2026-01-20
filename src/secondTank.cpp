#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int secondTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2])
{
    static bool Sogon = true;
    static bool Sup = false;
    static bool Sdown = false;
    static bool Sleft = false;
    static bool Sright = false;
    static int Sgo = 0;
    int vibor = 0;

    int Xcel = tank[0].x;
    int Ycel = tank[0].y;

    static bool Xcord = true;
    static bool Ycord = false;

    static Uint32 lastSwitch = 0;
    Uint32 now = SDL_GetTicks();

    if (now - lastSwitch >= 1000)
    {
        Xcord = !Xcord;
        Ycord = !Ycord;
        lastSwitch = now;
    }

    int randomazer = rand() % 1000;

    if(randomazer == 0)
    {
        vibor = 1 + rand() % 3;
    }

    if(vibor == 1 or vibor == 0)
    {
        if(tank[1].x > 0 and tank[1].x < 600)
        {
            Xcel = tank[1].x;
            Ycel = tank[1].y;
        }

        else
        {
            vibor = 2;
        }
    }

    if(vibor == 2)
    {
        if(tank[3].x > 0 and tank[3].x < 600)
        {
            Xcel = tank[3].x;
            Ycel = tank[3].y;
        }

        else
        {
            vibor = 3;
        }
    }

    if(vibor == 3)
    {
        if(tank[0].x > 0 and tank[0].x < 600)
        {
            Xcel = tank[0].x;
            Ycel = tank[0].y;
        }

        else
        {
            vibor = 1;
        }
    }



    if (bullet.x > -10 and bullet.x < 600 and bullet.y > -10 and bullet.y < 600)
        Sogon = false;
    else
        Sogon = true;

    if (Xcord)
    {
        if (tank[2].x > Xcel)
        {
            Sgo = 1;

            tank[2].x -= 2;
            if (SDL_HasRectIntersectionFloat(&tank[2], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[1]))
            {
                tank[2].x += 2;
            }
        }

        if (tank[2].x < Xcel)
        {
            Sgo = 2;

            tank[2].x += 2;
            if (SDL_HasRectIntersectionFloat(&tank[2], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[1]))
            {
                tank[2].x -= 2;
            }
        }

        if (Sogon and (Sgo == 1 or Sgo == 2))
        {
            bullet.x = tank[2].x + 15;
            bullet.y = tank[2].y + 15;

            Sup = Sdown = false;

            if (tank[2].x > Xcel)
            {
                Sleft = true;
                Sright = false;
            }
            else
            {
                Sright = true;
                Sleft = false;
            }
        }
    }

    if (Ycord)
    {
        if (tank[2].y > Ycel)
        {
            Sgo = 3;

            tank[2].y -= 2;
            if (SDL_HasRectIntersectionFloat(&tank[2], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[1]))
            {
                tank[2].y += 2;
            }
        }

        if (tank[2].y < Ycel)
        {
            Sgo = 4;

            tank[2].y += 2;
            if (SDL_HasRectIntersectionFloat(&tank[2], &tank[0]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[2], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[2], &wall[1]))
            {
                tank[2].y -= 2;
            }
        }

        if (Sogon and (Sgo == 3 or Sgo == 4))
        {
            bullet.x = tank[2].x + 15;
            bullet.y = tank[2].y + 15;

            Sleft = Sright = false;

            if (tank[2].y > Ycel)
            {
                Sup = true;
                Sdown = false;
            }
            else
            {
                Sdown = true;
                Sup = false;
            }
        }
    }

    if (Sup)
    {
        bullet.y -= 5;
    }

    if (Sdown)
    {
        bullet.y += 5;
    }

    if (Sleft)
    {
      bullet.x -= 5;
    }

    if (Sright)
    {
        bullet.x += 5;
    }

    if (bullet.x < -10 or bullet.x > 600 or bullet.y < -10 or bullet.y > 600)
    {
        Sup = Sdown = Sleft = Sright = false;
    }

    return Sgo;
}
