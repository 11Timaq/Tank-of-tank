#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <my_header.hpp>

using namespace std;

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* myWindow = SDL_CreateWindow("Tanks", 600, 600, 0);
    SDL_Renderer* mainRenderer = SDL_CreateRenderer(myWindow, NULL);
    
    SDL_Texture* textureBackground = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/Background.jpg");
    if(textureBackground == NULL) cout<<"fail load background\n";
    SDL_Texture* textureTankUp = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/TanksUp.png");
    if(textureTankUp == NULL) cout<<"fail load TankUp\n";
    SDL_Texture* textureTankDown = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/TanksDown.png");
    if(textureTankDown == NULL) cout<<"fail load TankDown\n";
    SDL_Texture* textureTankRight = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/TanksRight.png");
    if(textureTankRight == NULL) cout<<"fail load TankRight\n";
    SDL_Texture* textureTankLeft = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/TanksLeft.png");
    if(textureTankLeft == NULL) cout<<"fail load TankLeft\n";
    SDL_Texture* textureBullet = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/bullet.png");
    if(textureBullet == NULL) cout<<"fail load Bullet\n";
    SDL_Texture* textureWallFirst = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/wallFirst.png");
    if(textureWallFirst == NULL) cout<<"fail load WallFirst\n";
    SDL_Texture* textureWallSecond = IMG_LoadTexture (mainRenderer, "C:/Users/alex1/Desktop/Project/Tanks/data/wallSecond.png");
    if(textureWallSecond == NULL) cout<<"fail load WallSecond\n";



    SDL_FRect tank[4] = {
    {120, 480, 40, 40},
    {120, 120, 40, 40},
    {480, 120, 40, 40},
    {480, 480, 40, 40}
    };


    SDL_FRect wall[2] = {
    {160, 300, 320, 40},
    {300, 160, 40, 320}
    };

    SDL_FRect bullet[4] = {
    {700, 700, 10, 10},
    {700, 700, 10, 10},
    {700, 700, 10, 10},
    {700, 700, 10, 10}
    };

    int go = 0;
    int Fgo = 0;
    int Sgo = 0;
    int Tgo = 0;
    bool shoot = false;
    bool ogon = false;

    srand(time(NULL));

    SDL_UpdateWindowSurface(myWindow);
    SDL_Event o;
    bool quit = false;

    while(quit == false)
    {
        while(SDL_PollEvent(&o))
        {
            switch (o.type)
            {
            case SDL_EVENT_QUIT:
                quit = true;
                break;

            case SDL_EVENT_KEY_DOWN:
                switch(o.key.key)
                {
                    case SDLK_W:
                        printf("w\n");
                        go = 1;
                        break;
                    
                    case SDLK_S:
                        printf("s\n");
                        go = 2;
                        break;

                    case SDLK_A:
                        printf("a\n");
                        go = 3;
                        break;

                    case SDLK_D:
                        printf("d\n");
                        go = 4;
                        break;

                    case SDLK_SPACE:
                        if(shoot == false and go > 0)
                        {
                            printf("shoot\n");
                            shoot  = true;
                            ogon = true;
                        }
                        break;

                    default:
                        break;
                }
                break;
            
            default:
                break;
            }
        }

        

        move_myTank(go, tank, wall);

        shoot_myTank(go, shoot, ogon, tank[0], bullet[0]);

        if(tank[1].x < 800)
        {
            Fgo = firstTank(tank, bullet[1], wall);
        }

        if(tank[2].x < 800)
        {
            Sgo = secondTank(tank, bullet[2], wall);
        }

        if(tank[3].x < 800)
        {
            Tgo = thirdTank(tank, bullet[3], wall);
        }



        for(int i = 0; i < 4; i++)
        {
            if(SDL_HasRectIntersectionFloat(&bullet[i], &wall[0]) or SDL_HasRectIntersectionFloat(&bullet[i], &wall[1]))
            {
                bullet[i].x = 700;
                bullet[i].y = 700;
            }
        }



        if(SDL_HasRectIntersectionFloat(&tank[0], &bullet[1]) or SDL_HasRectIntersectionFloat(&tank[0], &bullet[2]) or SDL_HasRectIntersectionFloat(&tank[0], &bullet[3]))
        {
            quit = true;
        }

        if(SDL_HasRectIntersectionFloat(&tank[1], &bullet[0]) or SDL_HasRectIntersectionFloat(&tank[1], &bullet[2]) or SDL_HasRectIntersectionFloat(&tank[1], &bullet[3]))
        {
            tank[1].x = 900;
            tank[1].y = 900;
        }

        if(SDL_HasRectIntersectionFloat(&tank[2], &bullet[0]) or SDL_HasRectIntersectionFloat(&tank[2], &bullet[1]) or SDL_HasRectIntersectionFloat(&tank[2], &bullet[3]))
        {
            tank[2].x = 900;
            tank[2].y = 900;
        }

        if(SDL_HasRectIntersectionFloat(&tank[3], &bullet[0]) or SDL_HasRectIntersectionFloat(&tank[3], &bullet[1]) or SDL_HasRectIntersectionFloat(&tank[3], &bullet[2]))
        {
            tank[3].x = 900;
            tank[3].y = 900;
        }

        if(tank[1].x > 800 and tank[2].x > 800 and tank[3].x > 800)
        {
            quit = true;
        }



        SDL_RenderTexture(mainRenderer, textureBackground, NULL, NULL);

        for(int i = 0; i < 4; i++)
        {
            SDL_RenderTexture(mainRenderer, textureBullet, NULL, &bullet[i]); 
        }



        if(go == 1 or go == 0)
        {
            SDL_RenderTexture(mainRenderer, textureTankUp, NULL, &tank[0]);
        }

        if(go == 2)
        {
            SDL_RenderTexture(mainRenderer, textureTankDown, NULL, &tank[0]);
        }

        if(go == 3)
        {
            SDL_RenderTexture(mainRenderer, textureTankLeft, NULL, &tank[0]);
        }

        if(go == 4)
        {
            SDL_RenderTexture(mainRenderer, textureTankRight, NULL, &tank[0]);
        }



        if(Fgo == 1 or Fgo == 0)
        {
            SDL_RenderTexture(mainRenderer, textureTankUp, NULL, &tank[1]);
        }

        if(Fgo == 2)
        {
            SDL_RenderTexture(mainRenderer, textureTankDown, NULL, &tank[1]);
        }

        if(Fgo == 3)
        {
            SDL_RenderTexture(mainRenderer, textureTankLeft, NULL, &tank[1]);
        }

        if(Fgo == 4)
        {
            SDL_RenderTexture(mainRenderer, textureTankRight, NULL, &tank[1]);
        }



        if(Sgo == 1 or Sgo == 0)
        {
            SDL_RenderTexture(mainRenderer, textureTankLeft, NULL, &tank[2]);
        }

        if(Sgo == 2)
        {
            SDL_RenderTexture(mainRenderer, textureTankRight, NULL, &tank[2]);
        }

        if(Sgo == 3)
        {
            SDL_RenderTexture(mainRenderer, textureTankUp, NULL, &tank[2]);
        }

        if(Sgo == 4)
        {
            SDL_RenderTexture(mainRenderer, textureTankDown, NULL, &tank[2]);
        }



        if(Tgo == 1 or Tgo == 0)
        {
            SDL_RenderTexture(mainRenderer, textureTankUp, NULL, &tank[3]);
        }

        if(Tgo == 2)
        {
            SDL_RenderTexture(mainRenderer, textureTankDown, NULL, &tank[3]);
        }

        if(Tgo == 3)
        {
            SDL_RenderTexture(mainRenderer, textureTankLeft, NULL, &tank[3]);
        }

        if(Tgo == 4)
        {
            SDL_RenderTexture(mainRenderer, textureTankRight, NULL, &tank[3]);
        }

    

        SDL_RenderTexture(mainRenderer, textureWallFirst, NULL, &wall[0]);
        SDL_RenderTexture(mainRenderer, textureWallSecond, NULL, &wall[1]);

        SDL_RenderPresent(mainRenderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyTexture(textureBackground);
    SDL_DestroyTexture(textureTankUp);
    SDL_DestroyTexture(textureTankDown);
    SDL_DestroyTexture(textureTankRight);
    SDL_DestroyTexture(textureTankLeft);
    SDL_DestroyTexture(textureWallFirst);
    SDL_DestroyTexture(textureWallSecond);
    SDL_DestroyTexture(textureBullet);
    SDL_DestroyWindow(myWindow);
    SDL_Quit();

    return 0;
}
