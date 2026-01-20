#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

bool up = false;
bool down = false;
bool left = false; 
bool right = false;

void move_myTank(int go, SDL_FRect tank[4], SDL_FRect wall[2])
{
    if(go == 1)
    {
        if(tank[0].y != 0)
        {
            tank[0].y -= 2;
            if(SDL_HasRectIntersectionFloat(&tank[0], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[1]))
            {
                tank[0].y += 2;
            }
        }
    }

    if(go == 2)
    {
        if(tank[0].y != 560)
        {
            tank[0].y += 2;
            if(SDL_HasRectIntersectionFloat(&tank[0], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[1]))
            {
                tank[0].y -= 2;
            }
        }
    }

    if(go == 3)
    {
        if(tank[0].x != 0)
        {
            tank[0].x -= 2;
            if(SDL_HasRectIntersectionFloat(&tank[0], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[1]))
            {
                tank[0].x += 2;
            }
        }
    }

    if(go == 4)
    {
        if(tank[0].x != 560)
        {
            tank[0].x += 2;
            if(SDL_HasRectIntersectionFloat(&tank[0], &tank[1]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[2]) or SDL_HasRectIntersectionFloat(&tank[0], &tank[3]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[0]) or SDL_HasRectIntersectionFloat(&tank[0], &wall[1]))
            {
                tank[0].x -= 2;
            }
        }
    }
}

void shoot_myTank(int go, bool& shoot, bool& ogon, SDL_FRect& tank, SDL_FRect& bullet)
{
    if(shoot)
        {
            if(ogon)
            {
                bullet.x = tank.x + 15;
                bullet.y = tank.y + 15;

                if(go == 1)
                {
                    up = true;
                }

                if(go == 2)
                {
                    down = true;
                }

                if(go == 3)
                {
                    left = true;
                }

                if(go == 4)
                {
                    right = true;    
                }
            }
            ogon = false;

            if(up)
            {
                bullet.y -= 5;
            }

            if(down)
            {
                bullet.y += 5;
            }

            if(left)
            {
                bullet.x -= 5;
            }

            if(right)
            {
                bullet.x += 5;
            }

            if(bullet.y < -10 or bullet.y > 600 or bullet.x < -10 or bullet.x > 600)
            {
                shoot = false;
                ogon = false;
                up = false;
                down = false;
                left = false;
                right = false;
            }
        }
}