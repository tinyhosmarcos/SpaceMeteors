#ifndef METEORS_H_INCLUDED
#define METEORS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>

class meteors{
private:
    int position_x;
    int position_y;
    SDL_Surface* image_meteors;
    SDL_Texture* texture_meteors;
    SDL_Rect var_mov;
};

#endif // METEORS_H_INCLUDED
