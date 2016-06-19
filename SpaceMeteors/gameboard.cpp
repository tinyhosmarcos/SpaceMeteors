#include "gameboard.h"

void gameboard::Init_Video(){
    SDL_Init(SDL_INIT_VIDEO);


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
    image = IMG_Load("PICT.JPG");
    texture = SDL_CreateTextureFromSurface(renderer, image);

}
