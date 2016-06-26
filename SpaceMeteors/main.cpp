#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include "gameboard.h"
#include "nave.h"
#include "Asteroid_Belt.h"
#include <iostream>
#include <sstream>
#include <list>


using namespace std;
int main(int argc,char* argv[]){

    gameboard board; //init board;
    nave space("nave.png",board.Get_Renderer());//init nave;
    ASTEROID_BELT asteroids_belt(4,board.Get_Renderer());

    //meteors luna("meteor.png",board.Get_Renderer());//init meteor_test
    //


    //tipoX* ptr = new tipoX [size]
    SDL_Event event;

    bool quit=true;
    while(quit){

        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                        case SDLK_LEFT:  space.Set_position('x',space.Get_position('x')-1); break;
                        case SDLK_RIGHT: space.Set_position('x',space.Get_position('x')+1); break;
                        case SDLK_UP:    space.Set_position('y',space.Get_position('y')-1); break;
                        case SDLK_DOWN:  space.Set_position('y',space.Get_position('y')+1); break;
                        case SDLK_a:     space.shoot(board.Get_Renderer());

                    }

                std::stringstream ss;
                ss << "X: " << space.Get_position('x') << " Y: " <<space.Get_position('y');
                SDL_SetWindowTitle(board.Get_Windows(), ss.str().c_str());
                break;
        }



         //finaliza control de teclas
        //renders
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
