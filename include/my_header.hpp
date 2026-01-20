#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


void move_myTank(int go, SDL_FRect tank[4], SDL_FRect wall[2]);

void shoot_myTank(int go, bool& shoot, bool& ogon, SDL_FRect& tank, SDL_FRect& bullet);
 
int firstTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2]); 

int secondTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2]);
 
int thirdTank(SDL_FRect tank[4], SDL_FRect& bullet, SDL_FRect wall[2]);