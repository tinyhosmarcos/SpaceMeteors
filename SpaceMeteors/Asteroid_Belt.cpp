#include "Asteroid_Belt.h"
ASTEROID_BELT::ASTEROID_BELT(int num_asteroids,SDL_Renderer* temp_render){
    for(int i=0;i<num_asteroids;i++){
        asteroids.push_back(new meteors("meteor.png",temp_render));
    }
}
void ASTEROID_BELT::add_asteroid(int num_add_asteroids,SDL_Renderer* temp_render){
    for(int i=0;i<num_add_asteroids;i++){
        asteroids.push_back(new meteors("meteor.png",temp_render));
    }
}
void ASTEROID_BELT::init_rainy(SDL_Renderer* temp_render){
    for(ID_asteroid=asteroids.begin(); ID_asteroid!=asteroids.end();++ID_asteroid){
        SDL_RenderCopy(temp_render,(*ID_asteroid)->Get_Texture(),NULL, (*ID_asteroid)->movement());
        (*ID_asteroid)->movimiento();

    }
}
//SDL_Renderer* Get_Renderer(){return renderer;}
