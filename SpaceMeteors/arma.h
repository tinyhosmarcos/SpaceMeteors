#ifndef ARMA_H_INCLUDED
#define ARMA_H_INCLUDED
#include <SDL.h>
#include "SDL_Create.h"
#include <SDL_mixer.h>
class Weapons:public SDL_Create{
private:
    const char* file="bullet.png";
    const char* sound="shoot.wav";
public:
    Weapons(SDL_Renderer* temp_renderer,int post_x,int post_y);
    void init_movement();
    bool eraser_shoot();
};


#endif // ARMA_H_INCLUDED
