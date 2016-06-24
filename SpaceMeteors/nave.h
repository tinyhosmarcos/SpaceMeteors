#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "gameboard.h"
#include "arma.h"
#include <list>
using namespace std;
class nave{
private:
    int position_x;
    int position_y;
    SDL_Surface* image_ship;
    SDL_Texture* texture_ship;
    SDL_Rect var_mov;
    list<Weapons*>weapon;
    list<Weapons*>::iterator counter_shoots;

public:
    nave(const char* temp_file,SDL_Renderer* temp_renderer);
    void Set_Image(const char* file);
    void Create_Texture(SDL_Renderer* renderer);
    SDL_Texture* Get_Texture();
    int Get_position(char char_pos);
    void Set_position(char char_pos,int position_temp);
    SDL_Rect* movement();
    void Shoot(SDL_Renderer* temp_render);
    void delete_shoot(SDL_Renderer* temp_render);
};

#endif // NAVE_H_INCLUDED
