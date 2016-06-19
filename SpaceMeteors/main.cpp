#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include "gameboard.h"
#include "nave.h"
#include <sstream>

int main(int argc,char* argv[]){
    gameboard board;
    SDL_Event event;
    board.Init_Video();
    board.Init_Image();
    board.Create_Windows();
    board.Create_Map();
    nave space;
    space.Set_Image("Nave.png");
    space.Create_Texture(board.Get_Renderer());
    space.Set_position('x',50);
    space.Set_position('y',50);
    bool quit=true;
    while(quit){
        //evento de control de teclas
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                        case SDLK_LEFT:  space.Set_position('x',space.Get_position('x')-1); break;
                        case SDLK_RIGHT: space.Set_position('x',space.Get_position('x')+1); break;
                        case SDLK_UP:    space.Set_position('y',space.Get_position('y')-1); break;
                        case SDLK_DOWN:  space.Set_position('y',space.Get_position('y')+1); break;
                    }
                std::stringstream ss;
                ss << "X: " << space.Get_position('x') << " Y: " <<space.Get_position('y');
                SDL_SetWindowTitle(board.Get_Windows(), ss.str().c_str());
                break;
        }
         //finaliza control de teclas
        SDL_RenderCopy(board.Get_Renderer(), board.Get_Texture(), NULL, NULL);
        SDL_RenderCopy(board.Get_Renderer(), space.Get_Texture(), NULL,space.movement());
        SDL_RenderPresent(board.Get_Renderer());

    }
}
