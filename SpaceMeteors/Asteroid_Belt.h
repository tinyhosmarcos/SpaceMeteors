#ifndef ASTEROID_BELT_H_INCLUDED
#define ASTEROID_BELT_H_INCLUDED
#include "meteors.h"
#include <list>
#include <SDL.h>
using namespace std;
class ASTEROID_BELT{
private:
    list<meteors*> asteroids;
    list<meteors*>::iterator ID_asteroid;
public:
    ASTEROID_BELT(int num_asteroids,SDL_Renderer* temp_render);
    void add_asteroid(int num_add_asteroids,SDL_Renderer* temp_render);
    void init_rainy(SDL_Renderer* temp_renderer);
};


#endif // ASTEROID_BELT_H_INCLUDED
