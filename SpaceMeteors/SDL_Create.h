#ifndef SDL_CREATE_H_INCLUDED
#define SDL_CREATE_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
class SDL_Create{
protected:
    int position_x;
    int position_y;
    int length;
    int width;
    SDL_Surface* image;
    SDL_Texture* texture;
    Mix_Chunk* sound_effect;
    SDL_Rect var_mov;

public:
    void Set_Image(const char* file);
    void Set_Sound(const char* file);
    void Create_Texture(SDL_Renderer* renderer);
    SDL_Texture* Get_Texture();
    SDL_Rect* movemento();
    void proportions(int temp_width,int temp_length);
    void Set_position(char char_pos,int position_temp);
    int Get_position(char char_pos);
    Mix_Chunk* Get_Sound(){return sound_effect;};
};

#endif // SDL_CREATE_H_INCLUDED
