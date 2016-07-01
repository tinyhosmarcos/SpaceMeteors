#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <sstream>

using namespace std;
class gameboard{
private:
    SDL_Window *windows;
    SDL_Renderer* renderer;
    SDL_Surface* image;
    SDL_Surface* image2;
    SDL_Texture* texture;
    SDL_Texture* texture2;
    Mix_Music *music;
    const char* file_nave;

    //
public:
    gameboard();
    void Main_Game();
    void Main_Space();
    void Init_Video();
    void Init_Image();
    void Create_Windows();
    void Create_Map();
    SDL_Window* Get_Windows(){return windows;}
    SDL_Renderer* Get_Renderer(){return renderer;}
    SDL_Texture* Get_Texture(){return texture;}
    SDL_Texture* Get_Texture_2(){return texture2;}
    Mix_Music *Get_Music(){return music;};
    const char* Get_Nave(){return file_nave;};
    //void Init_Game();

};


#endif // GAMEBOARD_H_INCLUDED
