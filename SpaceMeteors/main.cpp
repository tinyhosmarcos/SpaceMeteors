#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include "gameboard.h"
#include "nave.h"
#include "Asteroid_Belt.h"
using namespace std;
int main(int argc,char* argv[]){

    gameboard board; //init board;
    nave space("nave.png",board.Get_Renderer());//init nave;
    ASTEROID_BELT asteroids_belt(4,board.Get_Renderer());



    SDL_Event event;

    bool quit=true;

    while(quit){
        space.controler(event,board.Get_Renderer());




         //finaliza control de teclas
        //renders
        SDL_RenderClear(board.Get_Renderer());
        SDL_RenderCopy(board.Get_Renderer(), board.Get_Texture(), NULL, NULL);
        SDL_RenderCopy(board.Get_Renderer(), space.Get_Texture(), NULL,space.movement());
        //SDL_RenderCopy(board.Get_Renderer(), luna.Get_Texture(),NULL, luna.movement());
        asteroids_belt.init_rainy(board.Get_Renderer(),space);
        space.shots_impact(board.Get_Renderer());
        SDL_RenderPresent(board.Get_Renderer());
        //Renders
    }

    return 0;

}

