#include "gameboard.h"
gameboard::gameboard(){
    Init_Video();
    Init_Image();
    Create_Windows();
    Create_Map();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music *musica=Mix_LoadMUS("beat.wav");
    Mix_PlayMusic(musica,-1);
};
void gameboard::Init_Video(){
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);


}
void gameboard::Init_Image(){
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
}
void gameboard::Create_Windows(){
    windows= SDL_CreateWindow("SDL2 Displaying Image",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1280, 680, 0);
}
void gameboard::Create_Map(){
    renderer = SDL_CreateRenderer(windows, -1, 0);
    image = IMG_Load("background.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, image);

}
